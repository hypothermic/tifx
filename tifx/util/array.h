 /************************************************************\
  *           ========== ==      ======= ==   ==             *
  *               ==             ==       == ==              *
  *               ==     ==  --- =======   ===               *
  *               ==     ==      ==       == ==              *
  *               ==     ==      ==      ==   ==             *
  *   Copyright (c) 2018 hypothermic <admin@hypothermic.nl>  *
  *                       MIT License                        *
 \************************************************************/

#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct
{
    int *array;
    size_t used;
    size_t size;
} Array;

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
        a->size *= 2;
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

#endif // ARRAY_H_