// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max = 1, Min = 1, res = INT_MIN;

        for(const int& val : nums) {
            if (val == 0) {
                Max = 1;
                Min = 1;
                res = max(val, res);
            } 
            else {
                int NewMax = max(Max * val, Min * val);
                NewMax = max(NewMax, val);
                int NewMin = min(Min * val, Max * val);
                NewMin = min(NewMin, val);
                Max = NewMax;
                Min = NewMin;
                res = max(Max, res);
            }
        }

        return res;
    }
};