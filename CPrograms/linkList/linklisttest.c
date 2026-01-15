#include "LINKLIST.H"
#include "BDSCTEST.H"
#define NULL 0

main() {
  START_TESTING("LINKLIST.C");

    TEST_CASE("Test can create node") {
        struct node* mynode;
        mynode = mknode(42);
        ASSERT(mynode->num == 42);
        ASSERT(mynode->next == NULL);
    }

    TEST_CASE("Test print list") {
        struct node* head;
        struct node* second;
        struct node* third;
        char list_str[100];
    
        head = mknode(1);
        second = mknode(2);
        third = mknode(3);
    
        head->next = second;
        second->next = third;
        ASSERT_STR(prnlist(head, list_str), "[1 -> 2 -> 3]");
    }

  END_TESTING();
}