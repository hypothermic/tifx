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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <debug.h>

void array_init(Array *a, size_t initialSize)
{
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void array_append(Array *a, int element)
{
    if (a->used == a->size)
    {
        //a->size *= 2;
        a->size++;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

