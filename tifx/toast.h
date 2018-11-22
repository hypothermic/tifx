 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef TOAST_H_
#define TOAST_H_

int __tifx_toast_len; // remaining sec
char* __tifx_toast_contents; // text

void tifx_toast_show(const char* text)
{
    __tifx_toast_len = 100;
    __tifx_toast_contents = text;
}

#endif // TOAST_H_