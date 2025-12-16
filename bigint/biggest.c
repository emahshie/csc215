#include <stdio.h>

main() {
    int biggest;
    unsigned ubiggest;
    unsigned n, m, prod;
    biggest = 32767;
    ubiggest = 65535;
    printf("The value of biggest is now %d.\n", biggest);
    printf("The value of ubiggest is now %u.\n", ubiggest);
    biggest++;
    ubiggest++;
    printf("Add 1 to it and we get %u!\n", biggest);
    printf("Add 1 to it and we get %d!\n", ubiggest);
    n =  65000;
    m = 3;
    prod = n * m;
    printf("%u * %u = %u -- Why?\n", m, n, prod);
    prod = biggest * ubiggest;
    printf("Multiply the two numbers to get %u!\n", prod);
    prod = biggest / ubiggest;
    printf("Divide the two numbers to get %u!\n", prod);
    prod = ubiggest / biggest;
    printf("Divide the other way to get %u!\n", prod);
}

/* notes on added tests:
        - multiplying results in 0 (which makes sense because the result is too large)
        - both division result in 0, which I didn't expect because 65535/32767 > 0
*/
