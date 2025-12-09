/* To run program after compiling:
Create two files: nums.txt & result.txt (can have any name)
Prompt: fadder nums.txt result.txt
Answer will be written into result.txt
*/
  
#include <stdio.h>

main(argc, argv)
int argc;
char **argv;
{
    FILE *infp, *outfp;
    int p;
    int sum;
    int num;
    int linesum;
    
    if (argc != 3) {
        printf("Usage: add <infile> <outfile>\n");
        return;
    }
    
    if ((infp = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        return;
    }
    
    if ((outfp = fopen(argv[2], "w")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        fclose(infp);
        return;
    }
    
    num = 0;
    linesum = 0;
    int m;
    m = 0;
    
    while (m == 0) {
            if (p >= '0' && p <= '9') {
                num = num * 10 + (p - '0');
            }
            else if (p == ' ' || p == '\t') {
                linesum = linesum + num;
                num = 0;
            }
            else if (p == '\n') {
                linesum = linesum + num;
                fprintf(outfp, "%d\n", linesum);
                printf("%d\n", linesum);
                num = 0;
                linesum = 0;
            }
            if((p = fgetc(infp)) == EOF){
                linesum = linesum + num;
                fprintf(outfp, "%d\n", linesum);
                printf("%d\n", linesum);
                num = 0;
                linesum = 0;
                break;
            }
        }
    
    fclose(infp);
    fclose(outfp);
    printf("done!\n");
}
