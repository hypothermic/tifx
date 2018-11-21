 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef ELEMENT_H_
#define ELEMENT_H_

typedef struct _element_t
{
    int eid;
} element_t;

element_t *_tifx_element_new()
{
    return (element_t*)malloc(sizeof(element_t));
}

void tifx_element_free(element_t *elm)
{
    free(elm);
}

#endif // ELEMENT_H_