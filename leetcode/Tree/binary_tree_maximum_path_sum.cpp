// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
private:
    int dfs(TreeNode* node, int& res_sum) {
            int best_sum = node->val;

            int left_res = 0, right_res = 0;
            if (node->left != nullptr) {
                left_res = dfs(node->left, res_sum);
                if (node->val + left_res > best_sum) {
                    best_sum = node->val + left_res;
                }
            }
            if (node->right != nullptr) {
                right_res = dfs(node->right, res_sum);
                if (node->val + right_res > best_sum) {
                    best_sum = node->val + right_res;
                }
            }
            if (best_sum > res_sum) {
                res_sum = best_sum;
            }
            if (left_res + right_res + node->val > res_sum) {
                res_sum = left_res + right_res + node->val;
            }

            return best_sum;
        };

public:
    int maxPathSum(TreeNode* root) {
        int res_sum = root->val;

        dfs(root, res_sum);
        return res_sum;
    }
};