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

// array.h

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

typedef struct _activity_t
{
    int id;
    Array *elements;
    bool state; // is running or not
} activity_t;

activity_t *tifx_activity_new(void);
void tifx_activity_free(activity_t *act);

// element.c

typedef void (*tifx_callback_element_render) (void);

typedef struct _element_t
{
    int eid;
    tifx_callback_element_render render_cb;
} element_t;

element_t *_tifx_element_new(void);
void tifx_element_free(element_t *elm);

// engine.c

typedef void (*tifx_callback_key_press) (activity_t*);
void tifx_activity_run(activity_t *act);
void tifx_activity_register_callback_keypress(tifx_callback_key_press cb);

// render.c

void __tifx_element_render(element_t *elm);

// toast.c

void tifx_toast_show(const char* text);

#endif

