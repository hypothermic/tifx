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

element_t *_tifx_element_new(void)
{
    return (element_t*)malloc(sizeof(element_t));
}

void tifx_element_free(element_t *elm)
{
    free(elm);
}

