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

// toast.c

void tifx_toast_show(const char* text);

// element.c

typedef struct _element_t
{
    int eid;
} element_t;

element_t *_tifx_element_new(void);
void tifx_element_free(element_t *elm);

// activity.c

typedef struct _activity_t
{
    int id;
    Array* elements;
} activity_t;

activity_t *tifx_activity_new(void);
void tifx_activity_free(activity_t *act);

// engine.c

typedef void (*tifx_callback_key_press) (kb_key_t);
void tifx_activity_run(activity_t *act);
void tifx_activity_register_callback_keypress(tifx_callback_key_press cb);

#endif

