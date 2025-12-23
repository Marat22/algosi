# https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        repeating = []
        nums_s = set()
        res = []
        for num in nums:
            if num in nums_s:
                res.append(num)
                if len(res) == 2:
                    return res
            nums_s.add(num)
        return res