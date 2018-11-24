 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#include "../tifx.h"
#include <debug.h>
#include <graphx.h>
#include <tice.h>

static void _tifx_element_label_render_default(void);

label_t *tifx_element_label_new(void)
{
    label_t *elm;
    elm = (label_t*)malloc(sizeof(label_t));
    elm->inherit_elm = _tifx_element_new();
    elm->inherit_elm->render_cb = _tifx_element_label_render_default;
    return elm;
}

static void _tifx_element_label_render_default(void)
{
    dbg_sprintf(dbgerr, "Note to self: \"TODO: add label renderer shapes. Don't be lazy!\"\n");
    // TODO!!! placeholder:
    gfx_SetColor(gfx_red);
    gfx_FillRectangle(16, 16, 32, 32);
}