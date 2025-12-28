# https://leetcode.com/problems/maximum-product-subarray/submissions/1867010968/

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        left_to_right = [0] * len(nums)
        right_to_left = [0] * len(nums)
        

        l = 0
        r = len(nums) - 1

        for _ in range(len(nums)):
            if nums[l] == 0:
                pass
            elif l == 0:
                left_to_right[l] = nums[l]
            else:
                prev = 1 if left_to_right[l-1] == 0 else left_to_right[l-1]
                left_to_right[l] = nums[l] * prev
            l += 1
            
            if nums[r] == 0:
                pass
            elif r == len(nums) - 1:
                right_to_left[r] = nums[r]
            else:
                prev = 1 if right_to_left[r+1] == 0 else right_to_left[r+1]
                right_to_left[r] = nums[r] * prev
            r -= 1

        res = nums[0]
        for i in range(len(nums)-1):
            res = max(res, left_to_right[i] * right_to_left[i+1])
            res = max(res, left_to_right[i])
            res = max(res, right_to_left[i+1])
        
        return res