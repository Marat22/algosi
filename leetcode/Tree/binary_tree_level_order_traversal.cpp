// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    void traverse(TreeNode* node, vector<vector<int>>& res, int& max_depth, int curr_depth) {
        if (node == nullptr) {
            return;
        }
        if (curr_depth > max_depth) {
            res.insert(res.end(), {node->val});
            max_depth = curr_depth;
        }
        else {
            res[curr_depth].insert(res[curr_depth].end(), node->val);
        }
        traverse(node->left, res, max_depth, curr_depth+1);
        traverse(node->right, res, max_depth, curr_depth+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int max_depth = -1;
        traverse(root, res, max_depth, 0);
        return res;
    }
};