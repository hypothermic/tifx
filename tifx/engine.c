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

static void _tifx_callback_key_press_noop(kb_key_t key);

static tifx_callback_key_press _cb_key = _tifx_callback_key_press_noop;

/*! Present the activity on the screen.
 *  
 */
void tifx_activity_run(activity_t *act)
{
    bool key, prevkey = false;
    
    dbg_sprintf(dbgout, "ACT RUN 1\n");
    
    gfx_Begin();
    gfx_SetColor(gfx_blue);
    gfx_FillRectangle(1, 1, 2, 2);
    gfx_FillScreen(gfx_white);
    dbg_sprintf(dbgout, "ACT RUN 2\n");

    while (true)
    {
        kb_Scan();
        key = kb_Data[1] == kb_2nd;

        dbg_sprintf(dbgout, ".");

        if (key && !prevkey) {
            switch (key) {
                case kb_Left:
                    dbg_sprintf(dbgout, "ACT RUN KEY LEFT\n");
                    gfx_FillScreen(0xC0);
                    break;
                case kb_Clear:
                    dbg_sprintf(dbgout, "ACT RUN KEY CLR\n");
                    return;
                default:
                    dbg_sprintf(dbgout, "ACT RUN KEY UNHANDLED\n");
                    break;
            }
        }
        prevkey = key;

        dbg_sprintf(dbgout, "ACT RUN 4\n");

        gfx_SetColor(gfx_red);
        gfx_FillRectangle(1, 1, 2, 2);
        gfx_SetColor(gfx_white);

        dbg_sprintf(dbgout, "ACT RUN 5\n");

        // Handle custom application keypresses
        _cb_key(key);

        dbg_sprintf(dbgout, "ACT RUN 6\n");

        gfx_SwapDraw();

        dbg_sprintf(dbgout, "ACT RUN 7\n");
    }

    dbg_sprintf(dbgout, "ACT RUN 8\n");

    gfx_End();
}

void tifx_activity_register_callback_keypress(tifx_callback_key_press cb)
{
    _cb_key = cb;
}

static void _tifx_callback_key_press_noop(kb_key_t key)
{
    
}

