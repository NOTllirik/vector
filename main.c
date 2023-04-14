#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(4);
    printf("%d", v.size);

    return 0;
}
