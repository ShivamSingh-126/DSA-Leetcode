class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        
        nums.sort()
        n=len(nums)
        total=0
        mid = nums[n // 2]

        for val in nums:
            total += abs(val - mid)

        return total