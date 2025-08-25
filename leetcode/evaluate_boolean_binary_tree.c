#include<stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if (root->val <= 1) {
        return root->val;
    }

    if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }

    if (root->val == 3) {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }

    return -1000;

}