 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

typedef struct _activity_t
{
    int id;
    Array* elements;
} activity_t;

activity_t *tifx_activity_new()
{
    activity_t *act = (activity_t*)malloc(sizeof(activity_t));
    array_init(act->elements, 0);
    return act;
}

void tifx_activity_free(activity_t *act)
{
    free(act);
}

#endif // ACTIVITY_H_