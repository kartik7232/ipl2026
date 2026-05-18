#include <stdio.h>

struct Bitfield{
    unsigned int firstbit:1;
    unsigned int secondbit:2;
    unsigned int thirdbit:3;
};

int main() {
    struct Bitfield a;
    
    a.firstbit = 1;
    a.secondbit = 2;
    a.thirdbit = 3;

    printf("firstbit:%u\n", a.firstbit);
    printf("secondbit:%u\n", a.secondbit);
    printf("thirdbit:%u\n", a.thirdbit);

    a.firstbit = 3;

    printf("\nAfter Assigning 3 to firstbit: \n");
    printf("firstbit = %u\n", a.firstbit);
    return 0;
}