#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool are_nodes_symmetric(struct TreeNode* node1, struct TreeNode* node2) {
    if (!node1 != !node2) {
        return false;
    };
    if (!node1 && !node2) {
        return true;
    }

    if (node1->val != node2->val) {
        return false;
    }

    return are_nodes_symmetric(node1->right, node2->left) && are_nodes_symmetric(node1->left, node2->right);
}

bool isSymmetric(struct TreeNode* root) {
    return are_nodes_symmetric(root, root);
}
