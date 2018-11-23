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

#include "../tifx/tifx.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <tice.h>
#include <debug.h>

void main(void)
{
    activity_t* act;
    element_t *label;

    os_ClrHome();

    os_SetCursorPos(2, 1);
    os_PutStrFull("Press any key for test");

    while (!os_GetCSC());

    act = tifx_activity_new();

    label = _tifx_element_new();
    array_append(act->elements, (intptr_t) label);
    
    // TODO: add render callback for the label (it'll show as a default purple square now)
    //label->render_cb = my_render_function;

    tifx_activity_run(act);

    tifx_activity_free(act);
}