// https://leetcode.com/problems/validate-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, double, double)> dfs = [&](TreeNode* node, double smallest, double biggest) -> bool {
            if (node == nullptr) {
                // printf("\tnode == nullptr\n");
                return true;
            }
            // printf("val=%d, smallest=%d, biggest=%d\n", node->val, smallest, biggest);

            if (node->val <= smallest || node->val >= biggest ) {
                // printf("\t%d <= %d || %d >= %d\n", node->val, smallest, node->val, biggest);
                return false;
            }

            return dfs(node->left, smallest, min(double(node->val), biggest)) && dfs(node->right, max((double)(node->val), smallest), biggest);

        };
        return dfs(root->left, -numeric_limits<double>::infinity(), root->val) && dfs(root->right, root->val, numeric_limits<double>::infinity());
    }
};
