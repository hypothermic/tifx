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
#include <debug.h>
#include <graphx.h>
#include <tice.h>

static void _tifx_callback_key_press_noop(activity_t *act);

static tifx_callback_key_press _cb_key = _tifx_callback_key_press_noop;

/*! Present the activity on the screen.
 *  
 */
void tifx_activity_run(activity_t *act)
{
    dbg_sprintf(dbgerr, "ACT RUN 1\n");
    
    gfx_Begin();
    gfx_SetColor(gfx_blue);
    gfx_FillRectangle(1, 1, 2, 2);
    gfx_FillScreen(gfx_white);
    dbg_sprintf(dbgerr, "ACT RUN 2\n");

    while (act->state)
    {
        while (!os_GetCSC());

        kb_Scan();

        _cb_key(act);

        dbg_sprintf(dbgerr, ".");

        gfx_SetColor(gfx_red);
        gfx_FillRectangle(1, 1, 2, 2);
        gfx_SetColor(gfx_white);

        gfx_SwapDraw();
    }

    dbg_sprintf(dbgerr, "ACT RUN 8\n");

    gfx_End();
}

void tifx_activity_register_callback_keypress(tifx_callback_key_press cb)
{
    _cb_key = cb;
}

static void _tifx_callback_key_press_noop(activity_t *act)
{
    dbg_sprintf(dbgerr, "Unhandled key press! Add a listener with tifx_activity_register_callback_keypress(tifx_callback_key_press cb)\n");
    if (kb_Data[6] & kb_Clear) {
        act->state = false;
    }
}