 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#include "tifx.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

activity_t *tifx_activity_new(void)
{
    activity_t *act;
    act = (activity_t*)malloc(sizeof(activity_t));
    act->cb_key_press = __tifx_callback_key_press_noop;
    array_init(act->elements, 1);
    return act;
}

void tifx_activity_free(activity_t *act)
{
    free(act);
}

void tifx_activity_add_element(activity_t *act, element_t *elm)
{
    array_append(act->elements, (intptr_t) elm);
}

