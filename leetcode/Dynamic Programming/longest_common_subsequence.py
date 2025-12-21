# https://leetcode.com/problems/longest-common-subsequence/

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [0] * len(text2)
        for char in text1:
            max_pre = 0
            for i in range(len(text2)):
                if text2[i] == char and dp[i] < max_pre + 1:
                    dp[i] = max_pre + 1
                else:
                    max_pre = max(max_pre, dp[i])
        return max(dp)
