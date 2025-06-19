#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct {
    int val;
    struct List *next_node;
} List;

int put_val_at_index(List list, int i, int val);

void put_val(List *list, const int val);  // puts in the end of list

void put_vals(List *list, int qty, ...);

int pop_item(List list, int i); // if element with i index dbggboesn't exist -> raise error

int get_item(List *list, unsigned int i); // if element with i index doesn't exist -> raise error

int get_len(List *list);

void print_list(List *list);

void sort_list(List *list);

List create_list(void);
#endif // LINKED_LIST_H

void delete_list(List *list);
