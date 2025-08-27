// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void update_array(struct Node* node, int **arr, int *returnSize, size_t *alloced) {

    if (true) { // this should be rewritten, but it is 6 A.M. and I should wake up at 7 A.M.
        *alloced += (node->numChildren + 10) * sizeof(int);
        *arr = realloc(*arr, *alloced);
        if (!*arr) {
            fprintf(stderr, "Failed to malloc in postorder");
            exit(-1);
        }
    }

    for (int i = 0; i < node->numChildren; i++) {
        update_array(node->children[i], arr, returnSize, alloced);
    }

    (*arr)[*returnSize] = node->val;
    *returnSize += 1; 
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return malloc(0);
    }
    *returnSize = 0;
    size_t alloced = sizeof(int);
    int *arr = malloc(alloced);

    if (!arr) {
        fprintf(stderr, "Failed to malloc in postorder");
        exit(-1);
    }

    update_array(root, &arr, returnSize, &alloced);

    return arr;
}

int main() {
    struct Node *child = malloc(sizeof(struct Node));

    child->val = 1;
    child->numChildren = 0;

    size_t childrenSize = sizeof(struct Node*);
    struct Node **children = malloc(childrenSize);
    children[0] = child;

    // struct Node A = {5, 0, NULL};
    // struct Node **B = {A};

    struct Node *node = malloc(sizeof(struct Node));
    node->val = 10;
    node->numChildren = 1;
    node->children = malloc(childrenSize);
    memcpy(node->children, children, childrenSize);

    int size = 0;
    int* res = postorder(node, &size);
    // res = postorder(node, &size);

    printf("%d", res[1]);    
    free(res);
}
