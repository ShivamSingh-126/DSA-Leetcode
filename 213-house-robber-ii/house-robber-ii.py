class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        if n==1:
            return nums[0]

        def solve(start,end):
            prevprev=0
            prev=0
            temp = 0

            for i in range(start,end):
                steal = nums[i-1] + prevprev
                skip = prev

                temp = max(steal,skip)

                prevprev = prev
                prev=temp

            return prev

        return max(solve(0,n-1),solve(1,n))
        

            
        