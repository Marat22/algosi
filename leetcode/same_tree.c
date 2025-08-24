#include<stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p || !q) {
        if (!p && !q) {
            return true;
        }
        return false;
    }

    if (p->val != q->val) {

        return false;
    }

    if ((!p->left) != (!q->left)) {
        return false;
    }

    if ((!p->right) != (!q->right)) {
        return false;
    }

    if (p->left && q->left) {
        if (!isSameTree(p->left, q->left)) {
            return false;
        }
    }

    if (p->right && q->right) {
        if (!isSameTree(p->right, q->right)) {
            return false;
        }
    }

    return true;
}