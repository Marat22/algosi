/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
public:
    TreeNode* deserialize(string data) {
        if (data.compare("null") == 0) {return nullptr;}
        regex del(";");

        sregex_token_iterator it(data.begin(),
                        data.end(), del, -1);

        sregex_token_iterator end;

       TreeNode* root = new TreeNode(stoi(*it));
        ++it;
        vector<TreeNode*> Last = {root};
        int z = 0;

        while (it != end && Last.size() > 0) {
            const size_t LastLen = Last.size();
            for (int i = 0; i < LastLen; i++) {
                TreeNode* node = Last[0];
                Last.erase(Last.begin());
                TreeNode* left;
                if (*it == "null") {
                    left = nullptr;
                } else {
                    left = new TreeNode(stoi(*it));;
                }
                it++;
                if (it == end) {return root;}
                TreeNode* right;
                if (*it == "null") {
                    right = nullptr;
                } else {
                    right = new TreeNode(stoi(*it));;
                }
                node->left = left;
                node->right = right;
                if (left != nullptr) {
                    Last.push_back(left);
                }
                if (right != nullptr) {
                    Last.push_back(right);
                }
                it++;

            }
        }

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        vector<TreeNode*> Last = {root};
        int z = 0;

        while (Last.size() > 0) {
            const size_t LastLen = Last.size();

            for (int i = 0; i < LastLen; i++) {
                const TreeNode* node = Last[0];
                Last.erase(Last.begin());
                if (node == nullptr) {
                    res += ";null";
                    continue;
                }
                else {
                    res += ";" + to_string(node->val);
                    TreeNode* left = node->left;
                    TreeNode* right = node->right;
                    Last.push_back( left);
                    Last.push_back( right);
                }
            }
        }
        if (res.size() > 0) {
            res.erase(res.begin());
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));