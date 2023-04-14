#include "vector.h"

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

bool isEmpty(vector *v){
    return v->size == 0;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isEmpty(v))
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size] = x;
    v->size += 1;
}

void popBack(vector *v){
    if (isEmpty(v)) {
        fprintf(stderr, "vector empty");
        exit(1);
    }

    reserve(v, v->size);
    v->size -= 1;
}
