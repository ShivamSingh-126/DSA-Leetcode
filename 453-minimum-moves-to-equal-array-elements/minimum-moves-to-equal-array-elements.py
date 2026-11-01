class Solution:
    def minMoves(self, nums: list[int]) -> int:

        n= len(nums)
        mini = min(nums)
        count=0
        for i in range(n):
            count += nums[i] - mini

        return count

