// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest = 0;
        int length;

      	for (int num: numsSet) {
            if (!numsSet.contains(num-1)) {
                length = 0;
                if (!numsSet.contains(num + longest)) {
                    continue;
                }
                while (numsSet.contains(num + length)) {
                    length += 1;
                }
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
