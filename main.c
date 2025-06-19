#include <stdio.h>
#include "linked_list.h"
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

void play_with_list();

typedef struct {
    int i;
} IntHolder;

union code
{
    IntHolder p;
    struct{
        unsigned a0:1;
        unsigned a1:1;
        unsigned a2:1;
        unsigned a3:1;
        unsigned a4:1;
        unsigned a5:1;
        unsigned a6:1;
        unsigned a7:1;
    } byte;
};


int main(void) {
    return 0;
}

void play_with_list() {

    int a;
    printf("%d\n", a);

    List list = create_list();
    // put_val(&list, 0); print_list(&list);  // FIXME: BUG

    // get_item(&list, 3);

    // delete_list(&list);
    // printf("before");
    // sleep(2);
    // printf("after");

    // printf("%d\n", get_len(&list));
    // puts("");
    //
    // put_val(&list, 34);
    // print_list(&list);
    // printf("%d\n", get_len(&list));
    // printf("list[0] %d\n", get_item(&list, 0));
    // puts("");
    //
    // put_vals(&list, 2, 1, 5);
    // print_list(&list);
    // printf("%d\n", get_len(&list));
    // puts("");
    //
    // put_val(&list, 3);
    // print_list(&list);
    // printf("%d\n", get_len(&list));
    // puts("");
    //
    // printf("list[0] %d\n", get_item(&list, 0));
    // printf("list[1] %d\n", get_item(&list, 1));
    // printf("list[2] %d\n", get_item(&list, 2));
    // printf("list[3] %d\n",

    // printf("list[4] %d\n", get_item(list, 4));

    // struct List *list2 = list.next_node;
    // printf("%d\n", list.val);
    // List *ptr = list.next_node;
    // printf("%d\n", ptr->val);
    // List *ptr2 = (*ptr).next_node;
    // printf("%d\n", ptr2->val);

    // put_vals(list, 3, 2, 123, 45);
    // print_list(&list);

    // printf("%d", get_item(list, 3));

    // printf("Hello, World!\n");

}
