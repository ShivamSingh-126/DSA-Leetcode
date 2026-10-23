class Solution(object):
    def sortPermutation(self, nums):
        if nums[0] != 0:
            return 0
        n = len(nums)
        ans = -1
        for i in range(n):
            if nums[i] != i:
                ans &= nums[i]
        
        return 0 if ans == -1 else ans
        