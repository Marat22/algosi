#include <stdlib.h>
#include "linked_list.h"
#include <stdio.h>
#include <stdarg.h>

int put_val_at_index(List list, int i, int val);

void put_val(List *list, const int val) {  // puts in the end of list
    List *list_ptr = list;
    while (list_ptr->val) {
        if (!list_ptr->next_node) {
            list_ptr->next_node = malloc(sizeof(List));
        }
        list_ptr = (List *)list_ptr->next_node;
    }
    list_ptr->val = val;
    list_ptr->next_node = NULL;
}

void put_vals(List *list, int qty, ...) {
    va_list args;
    va_start(args, qty);

    for (int i = 0; i < qty; ++i) {
        int next_arg = va_arg(args, int);
        put_val(list, next_arg);
    }

    va_end(args);
}

int pop_item(List list, int i); // if element with i index doesn't exist -> raise error

int get_item(List *list, unsigned int i) {
    // if element with i index doesn't exist -> raise error
    int count = 0;
    const List *list_ptr = list;

    while (list_ptr->val) {
        if (count++ == i) {
            return list_ptr->val;
        }

        list_ptr = (List *)list_ptr->next_node;
    }
    return 0;
}

int get_len(List *list) {
    int len = 0;

    List *list_ptr = list;
    while (list_ptr->next_node) {
        len++;
        // printf("DEBUG %d", len);
        list_ptr = (List *)list_ptr->next_node;
    }
    if (list_ptr->val) {
        len++;
    }

    return len;
}

void print_list(List *list) {
    List *list_ptr = list;
    printf("[");
    while (list_ptr->next_node) {
        printf("%d", list_ptr->val);
        list_ptr = (List *)list_ptr->next_node;
        if (list_ptr->val) {
            printf(", ");
        }
    }
    if (list_ptr->val) {
        printf("%d", list_ptr->val);
    }
    printf("]\n");
}

void sort_list(List *list) {
}

List create_list(void) {
    List* p = malloc(sizeof(List));
    printf("After init p->val = %d\n",  p->val);
    printf("After init p->next_node = %p\n",  p->next_node);
    free(p);
    List* z = malloc(sizeof(List));
    printf("After init z->val = %d\n",  z->val);
    printf("After init z->next_node = %p\n",  z->next_node);

    // free(p);
    // p = NULL;
    return *p;
}


void delete_list(List *list) {
    // List* next_ptr = (List *)list->next_node;
    // free(list);
    // if (next_ptr != NULL) {
    //     delete_list(next_ptr);
    // }

    while (1) {
        List* next_ptr; // = (List *)list->next_node;
        if (list->next_node != NULL) {
            printf("wtf0");
            break;
            next_ptr = list->next_node;
            free(list);
            list = next_ptr;
        }
        else {
            // printf("wtf\n");
            // fflush(stdout);
            free(list);
            // printf("wtf\n");
            // fflush(stdout);
            break;
        }
    }


}
