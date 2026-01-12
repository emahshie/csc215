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

int len(a,b)
struct bigint *a;
struct bigint *b;
{
    int alen, blen;
    alen = a->numdigits;
    blen = b->numdigits;
    if (alen > blen) {
        return alen;
    } else {
        return blen;
    }
}

void add_bigints(a, b, res) 
struct bigint *a;
struct bigint *b;
struct bigint *res;
{
    int MAX;
    char *result;
    int carry;
    int i;
    int digit_a;
    int digit_b;
    int sum;
    
    MAX = len(a,b);
    result = alloc(MAX + 2);
    carry = 0;
    
    for (i = 0; i < MAX; i++)
    {
        digit_a = (i < a->numdigits) ? (a->digits[i] - '0') : 0;
        digit_b = (i < b->numdigits) ? (b->digits[i] - '0') : 0;
        sum = digit_a + digit_b + carry;
        
        if (sum > 9) {
            carry = 1;
            result[i] = (sum - 10) + '0';
        }
        else {
            carry = 0;
            result[i] = sum + '0';
        }
    }
    
    if (carry) {
        result[MAX] = '1';
        result[MAX+1] = '\0';
        MAX++;
    } else {
        result[MAX] = '\0';
    }

    int p;
    p = 0;
    int o;
    o = MAX - 1;
    char temp;
    while (p < o) {
        temp = result[p];
        result[p] = result[o];
        result[o] = temp;
        p++;
        o--;
    }
    
    set_bigint(result, res);
}

void sub_bigints(a, b, res)
struct bigint *a;
struct bigint *b;
struct bigint *res;
{
    
}
