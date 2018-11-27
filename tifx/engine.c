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

/*! Present the activity on the screen.
 *  
 */
void tifx_activity_run(activity_t *act)
{
    int i;
    element_t *iter;

    dbg_sprintf(dbgerr, "ACT RUN %d\n", act->id);
    
    gfx_Begin();
    gfx_FillScreen(gfx_white);

    while (act->state)
    {
        kb_Scan();

        dbg_sprintf(dbgerr, "ACT UPDATE\n");

        act->cb_key_press(act);
        
        dbg_sprintf(dbgerr, "RENDERING %d ELEMENTS\n", act->elements->size);
        if (act->elements->size > 0)
        {
            for (i = 0; i < act->elements->size; i++)
            {
                dbg_sprintf(dbgerr, "RENDER ELEMENT %d\n", i);
                iter = (element_t*) act->elements->array[i];
                __tifx_element_render(iter);
            }
        }

        gfx_SwapDraw();

        // repeat once key is pressed, praise event-driven libraries!
        while (!os_GetCSC() && act->state);
    }

    dbg_sprintf(dbgerr, "ACT EXIT %d\n", act->id);

    gfx_End();
}

void tifx_activity_kill(activity_t *act)
{
    act->state = false;
}

void tifx_activity_register_callback_keypress(activity_t *act, tifx_callback_key_press cb)
{
    act->cb_key_press = cb;
}

void __tifx_callback_key_press_noop(activity_t *act)
{
    dbg_sprintf(dbgerr, "Unhandled key press! Add a listener with tifx_activity_register_callback_keypress(tifx_callback_key_press cb)\n");

    if (kb_Data[6] & kb_Clear)
    {
        act->state = false;
    }
}