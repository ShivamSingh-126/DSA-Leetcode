class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        n=len(nums)
        leftsum=0
        
        for i in range(n):

            rightsum=total-leftsum-nums[i]

            if leftsum == rightsum:
                return i

            leftsum += nums[i]

        return -1