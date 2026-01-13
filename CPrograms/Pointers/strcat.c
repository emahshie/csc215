/* Eleanor Mahshie */
#include <stdio.h>

char *strcat(char *x, char *y) {
  char *s, *t; 
  s = x;
  t = y;
  
  
    while (*s != '\0')
      s++;
    while ((*s = *t) != '\0')
      ;
  return s;
}
