#include <stdio.h>
#include "linked_list.h"
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"

void play_with_list();

int main(void) {
    // printf("%d\n", 10);
    // printf("%d\n", 10/10);
    // printf("%d\n", 10/10/10);
    play_with_list();
    return 0;
}

bool sort_func_(const int a, const int b) {
    // printf("%d - %d, %d - %d\n", a, a %10, b, b %10);
    return a % 10 > b % 10;
}

void play_with_list() {
    List *list = create_list();

    debug_print_list(list);
    append_val(list, 1);
    debug_print_list(list);
    append_val(list, 22);
    append_val(list, 41);

    printf("BEFORE INSERTION: \n");
    debug_print_list(list);
    insert_val_in_list(&list, 1, 10);
    printf("AFTER INSERTION: \n");
    debug_print_list(list);

    printf("\n\n");

    printf("AFTER SORTING:\n");
    sort_list(list, sort_func_);
    debug_print_list(list);

    // print_list(list);
    // printf("BEFORE DELETION:\n");
    // debug_print_list(list);
    //
    // const int deleted = pop_item(&list, 2);
    // printf("AFTER DELETION:\n");
    // debug_print_list(list);
    // printf("DELETED VALUE - %d\n", deleted);

    delete_list(list);
}
