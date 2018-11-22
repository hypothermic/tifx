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

typedef void (*tifx_callback_key_press) (sk_key_t);

static void _tifx_callback_key_press_noop(sk_key_t key);

static tifx_callback_key_press _cb_key = _tifx_callback_key_press_noop;

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

void tifx_activity_register_callback_keypress(tifx_callback_key_press cb)
{
    _cb_key = cb;
}

// todo: static?>
static void _tifx_callback_key_press_noop(sk_key_t key)
{
    
}

#endif // ENGINE_H_