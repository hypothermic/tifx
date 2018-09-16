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

typedef struct FxActivity
{
    int id;
    Array* elements;
} FxActivity;

FxActivity *tifx_activity_new()
{
    FxActivity *act = (FxActivity*)malloc(sizeof(FxActivity));
    array_init(act->elements, 0);
    return act;
}

void tifx_activity_free(FxActivity *win)
{
    free(win);
}

#endif // ACTIVITY_H_