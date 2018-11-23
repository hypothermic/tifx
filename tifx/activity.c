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
    array_init(act->elements, 0);
    return act;
}

void tifx_activity_free(activity_t *act)
{
    free(act);
}

