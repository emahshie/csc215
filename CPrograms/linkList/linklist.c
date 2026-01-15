#include <stdio.h>
#include "LINKLIST.H"
#define NULL 0

struct node *mknode(n) int n; {
    struct node* x;
    x = alloc(4);
    x->num = n;
    x->next = NULL;
    return x;
}

char* prnlist(list, list_str)
struct node* list;
char* list_str;
{
    struct node* p;
    char* ptr;
    char numbuf[10];
    int i, num, neg;
    
    ptr = list_str;
    p = list;
    *ptr++ = '[';
    
    while (p != NULL) {
        num = p->num;  
        neg = num < 0;
        if (neg) num = -num; 
        
        i = 0;
        do {
            numbuf[i++] = '0' + (num % 10);
            num /= 10;
        } while (num > 0);
        
        if (neg) numbuf[i++] = '-';
        while (--i >= 0) *ptr++ = numbuf[i];
        
        if (p->next != NULL) {
            *ptr++ = ' '; *ptr++ = '-'; *ptr++ = '>';
            *ptr++ = ' ';
        }
        p = p->next;
    }
    
    *ptr++ = ']';
    *ptr = '\0';
    return list_str;
}