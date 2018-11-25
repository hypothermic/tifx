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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <debug.h>

static void _tifx_callback_element_render_noop(void);

element_t *_tifx_element_new(void)
{
    element_t *elm;
    elm = (element_t*)malloc(sizeof(element_t));
    elm->render_cb = _tifx_callback_element_render_noop;
    elm->color = gfx_white;
    elm->padding_color = -1;
    elm->margin_color = -1;
    return elm;
}

void tifx_element_free(element_t *elm)
{
    free(elm);
}

static void _tifx_callback_element_render_noop(void)
{
    dbg_sprintf(dbgerr, "Unhandled element render! Replace member render_cb with your own tifx_callback_element_render\n");
    gfx_SetColor(gfx_purple);
    gfx_FillRectangle(1, 1, 8, 8);
}