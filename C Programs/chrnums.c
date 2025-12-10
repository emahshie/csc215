/*
Eleanor Mahshie
*/

#include <stdio.h>

main(argc, argv)
int argc;
char **argv;
{
  FILE *infp, *outfp;

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

  int linecount;
  linecount = 0;
  int count;
  count = 0;
  int b;
  b = 0;

  while (b==0) {


