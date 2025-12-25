// https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp (target + 1, 0);
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (dp[i] == 4611686018427387904) {
                    continue;
                }
                if (nums.at(j) > i) {
                    continue;
                }
                else if (nums.at(j) == i) {
                    dp[i] += 1;
                }
                else {
                    dp[i] += dp[i - nums[j]];
                }
            }
            cout << i << " "<< dp[i] << endl;
            // cout << dp[i] << endl;
        }
        return (int)(dp[target]);
    }
};
