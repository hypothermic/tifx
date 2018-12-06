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

static void _tifx_callback_element_render_noop(element_t* elm);

element_t *_tifx_element_new(void)
{
    element_t *elm;
    elm = (element_t*)malloc(sizeof(element_t));
    elm->render_cb = _tifx_callback_element_render_noop;
    elm->color = gfx_white;
    elm->padding_color = -1;
    elm->margin_color = -1;

    // temporary properties while render is being developed
    elm->width = 8;
    elm->height = 8;
    elm->color = gfx_white;

    return elm;
}

void tifx_element_free(element_t *elm)
{
    free(elm);
}

static void _tifx_callback_element_render_noop(element_t* elm)
{
    dbg_sprintf(dbgerr, "Unhandled element render! Replace member render_cb with your own tifx_callback_element_render\n");
    gfx_SetColor(elm->color);
    dbg_sprintf(dbgerr, "RENDERING w:%d h:%d\n", elm->width, elm->height);
    gfx_FillRectangle(0, 0, elm->width, elm->height);
}