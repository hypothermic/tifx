 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef TIFX_H_
#define TIFX_H_

// includes

#include <keypadc.h>
#include <stdint.h>
#include <string.h>

// fwd declarations

typedef struct _activity_t activity_t;
typedef struct _element_t element_t;

// array.c

typedef struct
{
    int *array;
    size_t used;
    size_t size;
} Array;

void array_init(Array *a, size_t initialSize);
void array_append(Array *a, int element);
void array_free(Array *a);

// activity.c

typedef void (*tifx_callback_key_press) (activity_t *act);

void __tifx_callback_key_press_noop(activity_t *act);

typedef struct _activity_t
{
    int id;
    Array *elements;
    bool state; // is running or not

    tifx_callback_key_press cb_key_press;
} activity_t;

activity_t *tifx_activity_new(void);
void tifx_activity_free(activity_t *act);

void tifx_activity_add_element(activity_t *act, element_t *elm);

// element.c

typedef enum _element_size
{
    ELEMENT_SIZE_EXPAND = 101,
    ELEMENT_SIZE_NOMINAL = 102,
} element_size;

typedef enum _element_visibility
{
    ELEMENT_VISIBILITY_VISIBLE = 0,
    ELEMENT_VISIBILITY_INVISIBLE = 1,
} element_visibility_t;

typedef void (*tifx_callback_element_render) (void);

typedef struct _element_t
{
    int eid;
    tifx_callback_element_render render_cb;

    uint8_t width; // px, or 101/102 (see enum element_size)
    uint8_t height; // ^idem
    uint8_t color /*= gfx_white*/; // (background) color
    element_visibility_t visibility;
    bool focusable; // if element can be in focus
    bool selectable; // if element can be selected (focusable must be true)

    uint8_t padding_color /*= -1*/; // optional. if this is -1, use color.
    uint8_t padding_top; // px
    uint8_t padding_bottom; // px
    uint8_t padding_left; // px
    uint8_t padding_right; // px

    uint8_t margin_color /*= -1*/; // optional. if this is -1, use color.
    uint8_t margin_top; // px
    uint8_t margin_bottom; // px
    uint8_t margin_left; // px
    uint8_t margin_right; // px
} element_t;

element_t *_tifx_element_new(void);
void tifx_element_free(element_t *elm);

// element/label.c

typedef struct _label_t
{
    element_t *inherit_elm;
    char* text;
} label_t;

label_t *tifx_element_label_new(void);

// engine.c

void tifx_activity_run(activity_t *act);
void tifx_activity_kill(activity_t *act);
void tifx_activity_register_callback_keypress(activity_t *act, tifx_callback_key_press cb);

// layout/list.c

/*
typedef struct _elist_t
{
    element_t *inherit_elm;
    char* text;
} elist_t; // list_t already exists in the TI-CE default libs...

elist_t *tifx_element_list_new(void);
*/

// render.c

void __tifx_element_render(element_t *elm);

// toast.c

void tifx_toast_show(const char* text);

#endif

