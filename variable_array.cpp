#include "variable _array.h"
#include <iostream>

template <class T>
Array<T> array_create(int init_size)
{
    Array<T> a;
    a.size = init_size;
    a.array = (T *)malloc(sizeof(T) * a.size);
    return a;
}

int user_input(void)
{
    printf("****This is the resizable array****\n");
    printf("press number -1 to show the array\n");
    int type;

    while (1)
    {
        printf("press 1 for integer, press 2 for double: ");
        // scanf("%d", &type);
        std::cin >> type;
        if (type == 1)

            break;

        else if (type == 2)

            break;

        else
            continue;
    }
    return type;
}

void array_operation(void)
{

    int type = user_input();
    if (type == 1)
    {
        int number;
        int counter = 0;
        Array<int> a = array_create<int>(4);
        while (number != -1)
        {
            printf("please enter an element:\n");
            scanf("%d", &number);
            if (number != -1)
            {
                *array_at<int>(&a, counter++) = number;
            }
            else
            {
                printf("Array: ");
                for (int i = 0; i < counter; i++)
                {
                    printf("%d ", *array_at<int>(&a, i));
                }
                break;
            }
        }
        array_free(&a);
    }
    else if (type == 2)
    {
        float number;
        int counter = 0;
        Array<float> a = array_create<float>(4);
        while (number != -1)
        {
            printf("please enter an element:\n");
            scanf("%f", &number);
            if (number != -1)
            {
                *array_at<float>(&a, counter++) = number;
            }
            else
            {
                printf("Array: ");
                for (int i = 0; i < counter; i++)
                {
                    printf("%f ", *array_at<float>(&a, i));
                }
                break;
            }
        }
        array_free(&a);
    }
}

template <class T>
void array_free(Array<T> *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

template <class T>
int array_size(const Array<T> *a)
{
    return a->size;
}

template <class T>
T *array_at(Array<T> *a, int index)
{
    if (index >= a->size)
    {
        array_inflate(a, 2);
    }
    return &(a->array[index]);
}

template <class T>
void array_inflate(Array<T> *a, int more_size)
{
    T *more = (T *)malloc(sizeof(T) * (a->size + more_size));
    int i;
    for (i = 0; i < a->size; i++)
    {
        more[i] = a->array[i];
    }

    free(a->array);
    a->array = more;
    a->size += more_size;
}
