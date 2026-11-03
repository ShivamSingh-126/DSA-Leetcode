class Solution:
    def minMoves(self, nums: List[int]) -> int:
        
        n=len(nums)
        maxi =max(nums)
        count=0

        for  x in nums:
            count += abs(x-maxi)

        return count
