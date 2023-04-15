#include "vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 11);
    assert(v.data[0] == 11);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    pushBack(&v, 11);
    assert(v.data[5] == 11);
    assert(v.capacity == 10);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    v.size = 5;
    v.data[3] = 14;

    assert (*(atVector(&v, 3)) == 14);
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    v.size = 5;
    v.data[4] = 14;

    assert (*(atVector(&v, 4)) == 14);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 14;

    assert (*(back(&v)) == 14);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 20;

    assert (*(front(&v)) == 20);
    deleteVector(&v);
}