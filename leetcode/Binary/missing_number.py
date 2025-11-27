# https://leetcode.com/problems/missing-number/


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        all_vals = set(range(0, len(nums) + 1))
        return all_vals.difference(set(nums)).__iter__().__next__()