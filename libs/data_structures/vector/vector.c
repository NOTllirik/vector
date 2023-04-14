#include <stdlib.h>
#include <stdio.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n) {
    vector vector;
    vector.data = (int *) malloc(n * sizeof (int));
    vector.capacity = n;
    vector.size = 0;
    if (vector.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vector;
}

void reserve(vector *v, size_t newCapacity){
    v->data = (int *) realloc( v->data, newCapacity * sizeof(int));
    v->capacity = newCapacity;
    if (newCapacity == 0)
        v->data = NULL;
    if (v->size > v->capacity)
        v->size = v->capacity;
    if (v->data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
}
