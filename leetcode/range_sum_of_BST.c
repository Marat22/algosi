struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

update_sum_recurs(struct TreeNode* node, int low, int high, int *sum) {
    if (node->val >= low && node->val <= high) {
        *sum += 1;
    }
    
    if (node->val < low && node->right) {
        update_sum_recurs(node->right, node->val, high, sum);
    }
    else if 
        (node->val > high && node->left) {
        update_sum_recurs(node->left, low, node->val, sum);
    }
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum = 0;

    update_sum_recurs(root, low, high, &sum);

    return sum;
}
