#include <stdio.h>
#include "BIGINT.H"

void set_bigint(numstr, num)
char *numstr;
struct bigint *num;
{
    char last_pos, i;
    num->negative = (numstr[0] == '-');
    num->numdigits = strlen(numstr) - num->negative;
    num->digits = alloc(num->numdigits);
    last_pos = num->numdigits + (num->negative ? 0 : -1);

    for (i = 0; i < num->numdigits; i++) {
        num->digits[i] = numstr[last_pos-i];
        /* printf("numstr[%d] is %c\n", last_pos-i, numstr[last_pos-i]); */
    }
}

char* get_bigint(num)
struct bigint *num;
{
   char *numstr;
   char start_pos, i;
   numstr = alloc(num->numdigits + (num->negative ? 2 : 1));
   start_pos = num->negative;
   if (start_pos == 1) numstr[0] = '-';
   for (i = 0; i < num->numdigits; i++) {
       numstr[i+start_pos] = num->digits[num->numdigits-(i+1)];
       /* printf("numstr[%d] is %c\n", i, numstr[i+start_pos]); */
   }
   numstr[num->numdigits+start_pos] = '\0';
   return numstr;
}

struct bigint add_bigint(struct bigint *num1, struct bigint *num2) {
    struct bigint result;
    int carry = 0;
    int maxDigits = (num1->numdigits > num2->numdigits) ? num1->numdigits : num2->numdigits;

    // Allocate enough space for the result
    result.digits = alloc(maxDigits + 1); // +1 for possible carry
    result.numdigits = 0;
    result.negative = 0; // Assuming positive results for now

    for (int i = 0; i < maxDigits || carry != 0; i++) {
        int digit1 = (i < num1->numdigits) ? num1->digits[i] - '0' : 0;
        int digit2 = (i < num2->numdigits) ? num2->digits[i] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        // Store the current digit
        result.digits[result.numdigits++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Null-terminate the result manually
    result.digits[result.numdigits] = '\0';

    return result;
}