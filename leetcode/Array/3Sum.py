class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        res = set()

        for i in range(0, len(nums) - 2):

            if nums[i] > 0:
                break
            left = i + 1
            right = len(nums) - 1

            target = 0 - nums[i]

            while left < right:
                sum_ = nums[left] + nums[right] + nums[i]
                if sum_ == 0:
                    new_val = (nums[left], nums[right], nums[i])

                    left += 1
                    right -= 1

                    res.add(new_val)
                elif sum_ < 0:
                    left += 1
                else:
                    right -= 1
        return [list(i) for i in res]
