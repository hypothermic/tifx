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

#include "tifx.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <tice.h>
#include <debug.h>

void main(void)
{
    activity_t* act;

    os_ClrHome();

    os_SetCursorPos(2, 1);
    os_PutStrFull("Press any key for test");

    dbg_sprintf(dbgout, "MAIN 1\n");

    while (!os_GetCSC());

    act = tifx_activity_new();

    dbg_sprintf(dbgout, "MAIN 2\n");

    tifx_activity_run(act);

    dbg_sprintf(dbgout, "MAIN 3\n");

    tifx_activity_free(act);
}
