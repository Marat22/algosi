// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void dfs(priority_queue<int, vector<int>, greater<int>>& pq, TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        // cout << "push " << node->val << endl;
        pq.push(node->val);

        if (node->left != nullptr) {
            dfs(pq, node->left);
        }
        if (node->right != nullptr) {
            dfs(pq, node->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> from_big_to_smallest;
        priority_queue<int, vector<int>, greater<int>> pq;
        // priority_queue<int, vector<int>, greater<int>> pq;
        dfs(pq, root);
        int res = 1312321;
        while (k != 0 && (!pq.empty())) {
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
   
        
    }
};