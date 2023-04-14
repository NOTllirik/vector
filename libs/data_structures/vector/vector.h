#ifndef MAIN_C_VECTOR_H
#define MAIN_C_VECTOR_H
#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

int f(int a);

#endif //MAIN_C_VECTOR_H
