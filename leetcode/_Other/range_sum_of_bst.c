
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void update_sum_recurs(struct TreeNode* node, int low, int high, int *sum) {
    if (node->val >= low && node->val <= high) {
        *sum += node->val;
    }
    
    if (node->val < low && node->right) {
        update_sum_recurs(node->right, low, high, sum);
    }
    else if 
        (node->val > high && node->left) {
        update_sum_recurs(node->left, low, high, sum);
    }
    else {
        if (node->left) {
            update_sum_recurs(node->left, low, high, sum);
        }
        if (node->right)
            update_sum_recurs(node->right, low, high, sum);
    }
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum = 0;

    update_sum_recurs(root, low, high, &sum);

    return sum;
}
