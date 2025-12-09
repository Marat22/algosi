// https://leetcode.com/problems/top-k-frequent-elements/submissions/1851470008/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count.reserve(nums.size());

        for (const auto& num : nums) {
            count[num]++;
        }

        vector<vector<int>> bucket (nums.size() + 1);
        for (auto &p : count) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> res;
        res.reserve(k);

        for (int z = bucket.size() - 1; z >= 0; z --) {
            for (int j = bucket[z].size() - 1; j >= 0; j--) {
                if (res.size() == k) {
                    return res;
                }

                res.push_back(bucket[z][j]);
            }
        }

        return res;
    }
};