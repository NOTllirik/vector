#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(4);
    for (int i = 0; i < 4; i++)
        v.data[i] = i;

    v.size = 2;
    shrinkToFit(&v);
    for (int i = 0; i < 4; i++)
        printf("%d ", v.data[i]);
    return 0;
}
