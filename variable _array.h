#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#include <stdlib.h>

template <class T>
struct Array
{
    T *array;
    int size;
};

int user_input(void);

void array_operation(void);

template <class T>
Array<T> array_create(int init_size);

template <class T>
void array_free(Array<T> *a);

template <class T>
int array_size(const Array<T> *a);

template <class T>
T *array_at(Array<T> *a, int index);

template <class T>
void array_inflate(Array<T> *a, int more_size);

#endif