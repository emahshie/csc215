#include <stdio.h>

main (argc, argv)
int argc;
char **argv;
{
    int i;
    int j;
    int sum;
    sum = 0;
    for (i = 1; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++){
            if (argv[i][j] < '0' || argv[i][j] > '9'){
                printf("%s isn't a number", argv[i]);
                return -1;
            }
        }
        sum += atoi(argv[i]);
    }
    printf("sum: %u", sum);
    return 0;
}
