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

static int __tifx_toast_len; // remaining sec
static char* __tifx_toast_contents; // text

void tifx_toast_show(const char* text)
{
    __tifx_toast_len = 100;
    __tifx_toast_contents = text;
}

