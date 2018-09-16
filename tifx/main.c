 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/
 /*----------------------------------------------------------*\
  This class is a placeholder/example for your own application
 \*----------------------------------------------------------*/

#include "../include/tifx.h"

void main()
{
    FxActivity* act;

    os_ClrHome();

    os_SetCursorPos(2, 1);
    os_PutStrFull("Press any key for test");

    while (!os_GetCSC());

    act = tifx_activity_new();

    tifx_activity_free(act);
}