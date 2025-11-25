// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int preorderIndex;
    unordered_map<int, int> mapping;
private:
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, inorder, start, mid - 1);
        root->right = build(preorder, inorder, mid + 1, end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        preorderIndex = 0;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};