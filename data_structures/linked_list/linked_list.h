#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<stdbool.h>
extern const int YOUR_MOTHER;

typedef struct {
    int len;
    int val;
    struct List *next_node;
} List;

void insert_val_in_list(List **list, unsigned int i, int val);

void append_val(List *list, const int val); // puts in the end of list

void append_vals(List *list, int qty, ...);

int pop_item(List **list, unsigned int i); // if element with i index dbggboesn't exist -> raise error

int get_item(List *list, unsigned int i); // if element with i index doesn't exist -> raise error

int get_len(const List *list);

void print_list(const List *list);

void debug_print_list(List *list);

/**
 *
 * @param a Val of index i
 * @param b Val of index i + 1
 * @return true - if `a` and `b` should be swapped, false - in other case.
 */
typedef bool sort_func(int a, int b);

void sort_list(List *list, sort_func sort_func_);

List *create_list(void);
#endif // LINKED_LIST_H

void delete_list(List *list);

/**
 * Changes the value at index `i` in `list`.
 * @param list List
 * @param i Index
 * @param val New value
 */
void set_val(List *list, unsigned i, int val);
