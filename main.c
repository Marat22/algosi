#include <assert.h>
#include <stdio.h>
#include "linked_list.h"
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"

void play_with_list();
void test_list();

int main(void) {
    test_list();
    return 0;
}


void play_with_list() {
    // debug_print_list(list);
    // append_val(list, 1);
    // debug_print_list(list);
    // append_val(list, 22);
    // append_val(list, 41);
    //
    // printf("BEFORE INSERTION: \n");
    // debug_print_list(list);
    // insert_val_in_list(&list, 1, 10);
    // printf("AFTER INSERTION: \n");
    // debug_print_list(list);
    //
    // printf("\n\n");
    //
    // printf("AFTER SORTING:\n");
    // sort_list(list, sort_func_);
    // debug_print_list(list);

    // print_list(list);
    // printf("BEFORE DELETION:\n");
    // debug_print_list(list);
    //
    // const int deleted = pop_item(&list, 2);
    // printf("AFTER DELETION:\n");
    // debug_print_list(list);
    // printf("DELETED VALUE - %d\n", deleted);

}

bool from_small_to_big(const int a, const int b) {
    return a > b;
}

void test_list() {
    printf("TEST LISTS\n");

    List *list = create_list();

    assert(get_len(list) == 0);

    {  // APPEND ONE VAL
        append_val(list, 10);
        assert(get_item(list, 0) == 10);
        assert(get_len(list) == 1);
    }
    printf("    APPEND ONE VAL ... OK\n");


    {  // APPEND SEVERAL VALS
        append_vals(list, 3, 100, 300, 400);
        assert(get_item(list, 1) == 100);
        assert(get_item(list, 2) == 300);
        assert(get_item(list, 3) == 400);
        assert(get_len(list) == 4);
    }
    printf("    APPEND SEVERAL VALS ... OK\n");

    {  // INSERT VAL
        insert_val_in_list(&list, 2, 200);
        assert(get_item(list, 2) == 200);
        assert(get_item(list, 1) == 100);
        assert(get_item(list, 3) == 300);
        assert(get_len(list) == 5);
    }
    printf("    INSERT VAL ... OK\n");

    {  // POP FIRST VAL
        const int popped_item = pop_item(&list, 0);
        assert(popped_item == 10);
        assert(get_len(list) == 4);
        assert(get_item(list, 0) == 100);
    }
    printf("    POP FIRST VAL ... OK\n");

    {  // POP VAL FROM MIDDLE
        const int popped_item = pop_item(&list, 2);
        assert(popped_item == 300);
        assert(get_len(list) == 3);
        assert(get_item(list, 2) == 400);
    }
    printf("    POP VAL FROM MIDDLE ... OK\n");

    {  // POP LAST VAL
        const int popped_item = pop_item(&list, 2);
        assert(popped_item == 400);
        assert(get_len(list) == 2);
        assert(get_item(list, 1) == 200);
        assert(get_item(list, 0) == 100);
    }
    printf("    POP LAST VAL ... OK\n");

    {  // CLEAR LIST
        while (get_len(list)) {
            pop_item(&list, 0);
        }
        assert(get_len(list) == 0);
    }

    {  // SORT LIST
        append_vals(list, 10, 1000, 1, 345, 7, 3, 1, 6, 54, 9, 10);
        sort_list(list, from_small_to_big);
        for (int i = 1; i < get_len(list); i++) {
            const int prev_item = get_item(list, i-1);
            const int cur_item = get_item(list, i);

            assert(prev_item <= cur_item);
        }
    }
    printf("    SORT LIST ... OK\n");

    delete_list(list);
}
