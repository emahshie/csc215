/* Eleanor Mahshie */
#include <stdio.h>

void reverse(char *s)
{
    char *start = s;
    char *end = s;
    char tmp;

    if (s == NULL)           
        return;

    while (*end != '\0')
        end++;

   
    if (end != s)
        end--;

    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}
