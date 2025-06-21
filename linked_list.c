#include <stdlib.h>
#include "linked_list.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "utils.h"
#include <stdbool.h>
#include <threads.h>

const int YOUR_MOTHER = 10000;

void insert_val_in_list(List **list, const unsigned int i, int val) {
    if (get_len(*list) < i) {
        printf("YOU ARE A STUPID PIECE OF SHIT, `i` MUST BE LESS OR EQUAL TO %d, YOUR `i` = %d\n", get_len(*list), i);
        return;
    }

    if (i == get_len(*list)) {
        append_val(*list, val);
        return;
    }

    if (i == 0) {
        List *new_node = malloc(sizeof(List));

        new_node->val = val;
        new_node->len = (*list)->len + 1;
        new_node->next_node = *list;

        *list = new_node;
        return;
    }

    List *node_to_change = NULL;
    for (int z = 0; z < i; z++) {
        if (node_to_change == NULL) node_to_change = *list;
        else node_to_change = (List *) node_to_change->next_node;
        node_to_change->len++;
    }

    List *new_node = malloc(sizeof(List));

    if (new_node == NULL) {
        printf("GO DUCK YOURSELF, WHAT'S WRONG WITH YOU, WHY YOU DON'T HAVE ENOUGH MEMORY FOR"
            " A DUCKING POINTER, HOW'S THAT POSSIBLE, I HATE YOU MAN");

        malloc(sizeof(YOUR_MOTHER)); // I WON'T FREE THAT MEMORY, STUPID ASSHOLE
        return;
    }

    new_node->val = val;
    new_node->len = node_to_change->len - 1;
    new_node->next_node = node_to_change->next_node;

    node_to_change->next_node = new_node;
}

void append_val(List *list, const int val) {
    // puts in the end of list
    List *ptr = list;
    while (ptr->len != 0) {
        ptr->len++;
        ptr = (List *) ptr->next_node;
    }
    ptr->len++;
    ptr->val = val;
    ptr->next_node = malloc(sizeof(List));

    List next_node = *(List *) ptr->next_node;
    next_node.len = 0;
}

void append_vals(List *list, const int qty, ...) {
    va_list args;
    va_start(args, qty);

    for (int i = 0; i < qty; ++i) {
        int next_arg = va_arg(args, int);
        append_val(list, next_arg);
    }

    va_end(args);
}

int pop_item(List **list, unsigned int i) {
    if (get_len(*list) <= i) {
        printf("YOU ARE A STUPID PIECE OF SHIT, `i` MUST BE LESS THAN %d, YOUR `i` = %d\n", get_len(*list), i);
        return 1;
    }

    if (i == 0) {
        const int val = (*list)->val;
        List *next_ptr = (List *) ((*list)->next_node);
        free(*list);
        *list = next_ptr;
        return val;
    }
    List *ptr_to_list_to_change = *list;
    ptr_to_list_to_change->len--;
    while (--i) {
        ptr_to_list_to_change = (List *) ptr_to_list_to_change->next_node;
        ptr_to_list_to_change->len--;
    }
    List *replacement_ptr = (List *) ((List *) ptr_to_list_to_change->next_node)->next_node;
    const int val = ((List *) ptr_to_list_to_change->next_node)->val;
    free(ptr_to_list_to_change->next_node);
    ptr_to_list_to_change->next_node = replacement_ptr;

    return val;
}

int get_item(List *list, unsigned int i) {
    if (get_len(list) <= i) {
        printf("YOU ARE A STUPID PIECE OF SHIT, `i` MUST BE LESS THAN %d, YOUR `i` = %d\n", get_len(list), i);
        return 1;
    }
    // if element with i index doesn't exist -> raise error
    int count = 0;
    const List *list_ptr = list;

    while (list_ptr->val) {
        if (count++ == i) {
            return list_ptr->val;
        }

        list_ptr = (List *) list_ptr->next_node;
    }
    return 0;
}

int get_len(const List *list) {
    return list->len;
}


void debug_print_list(List *list) {
    List *ptr = list;
    int len = ptr->len;

    printf("\tlen\tval\tnext_node\taddress\n");
    for (int i = 0; i <= len; i++) {
        printf("\t%d\t%d\t%p\t%p\n", ptr->len, ptr->val, ptr->next_node, ptr);
        ptr = (List *) ptr->next_node;
    }
}

void print_list(const List *list) {
    const List *ptr = (List *) list;

    const unsigned int output_len = 2 + GET_MAX_INT((list->len - 1) * 2, 0) + list->len * get_max_number_len() + 1;
    char str[output_len];
    strcpy(str, "[");

    for (int i = 0; i < list->len; i++) {
        const int val = ptr->val;
        char str_int[get_max_number_len() + 2 + 1];

        if (i < list->len - 1) snprintf(str_int, get_max_number_len(), "%d, ", val);
        else snprintf(str_int, get_max_number_len(), "%d", val);

        strcat(str, str_int);

        ptr = (List *) ptr->next_node;
    }
    strcat(str, "]");

    printf("%s\n", str);
}

// void simple_print(const List *list) {
//     int len = get_len(list);
//     List *p = list;
//     printf("[");
//     for (int i = 0; i < len; i++) {
//         printf("%d", p->val);
//         if (i < len - 1) {
//             printf(", ");
//         }
//         p = (List *) p->next_node;
//     }
//     printf("]\n");
// }

void sort_list(List *list, sort_func sort_func_) {
    // len == 1 -> exit
    // len == 0 -> exit
    while (true) {
        bool unchanged = true;

        List* cur_ptr = NULL;
        for (int i = 1; i < list->len; i++) {
            if (cur_ptr == NULL) {
                cur_ptr = list;
            }
            List *next_ptr = (List *)cur_ptr->next_node;
            // printf("VAL %d\n", cur_ptr->val);
            if (sort_func_(cur_ptr->val, next_ptr->val)) {
                cur_ptr->val ^= next_ptr->val;
                next_ptr->val ^= cur_ptr->val;
                cur_ptr->val ^= next_ptr->val;

                unchanged = false;
            }
            cur_ptr = next_ptr;
        }
        if (unchanged) break;
    }
}

List *create_list(void) {
    List *p = malloc(sizeof(List));
    p->len = 0;
    return p;
}

void delete_list(List *list) {
    List *ptr = NULL;
    const int len = list->len;
    for (int i = 0; i < len + 1; i++) {
        if (ptr == NULL) {
            ptr = list;
        }
        List *next_ptr = (List *) ptr->next_node;
        free(ptr);
        ptr = NULL;
        ptr = next_ptr;
    }
}

void set_val(List *list, const unsigned i, const int val) {
    List *ptr = list;

    while (list->len-i != ptr->len) {
        ptr = (List *)ptr->next_node;
    }

    ptr->val = val;
}
