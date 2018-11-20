 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef ENGINE_H_
#define ENGINE_H_

/*! Present the activity on the screen.
 *  
 */
void tifx_activity_run(activity_t *act)
{
    sk_key_t keybuf;
    
    gfx_Begin();
    gfx_FillScreen(gfx_white);

    while ((keybuf = os_GetCSC()) != sk_Clear) {
        switch (keybuf) {
            case sk_Down:
                break;
            // TODO
            default:
                break;
        }
        gfx_SwapDraw();
    }

    // Main activity loop

    gfx_End();
}

#endif // ENGINE_H_