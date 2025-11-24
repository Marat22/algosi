// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool compare(TreeNode* curRoot, TreeNode* subRoot) {
        if (curRoot == nullptr || subRoot == nullptr) {
            return curRoot == nullptr && subRoot == nullptr;
        }
        if (curRoot->val != subRoot->val) {
            return false;
        }
        if (compare(curRoot->left, subRoot->left) && compare(curRoot->right, subRoot->right)) {
            return true;
        }
        return false;
    }

    bool explore(TreeNode* curRoot, TreeNode* subRoot) {
        if (curRoot == nullptr || subRoot == nullptr) {
            return curRoot == nullptr && subRoot == nullptr;
        }
        if (curRoot->val == subRoot->val) {
            if (compare(curRoot, subRoot)) {
                return true;
            }
        }
        if (explore(curRoot->left, subRoot) || explore(curRoot->right, subRoot)) {
            return true;
        };
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return explore(root, subRoot);
    }
};