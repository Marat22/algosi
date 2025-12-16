# https://leetcode.com/problems/longest-increasing-subsequence/

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []

        for num in nums:
            if len(res) == 0 or res[-1] < num:
                res.append(num)
            else:
                res[ bisect.bisect_left(res, num) ] = num
        return len(res)
