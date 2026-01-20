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
    int i, neg;
    
    ptr = list_str;
    p = list;
    *ptr++ = '[';
    
    while (p != NULL) {
        i = 0;
        neg = p->num < 0;
        if (neg) p->num = -p->num;
        
        do {
            numbuf[i++] = '0' + (p->num % 10);
            p->num /= 10;
        } while (p->num > 0);
        
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