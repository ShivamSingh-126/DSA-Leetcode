class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        ans=0

        def solverec(nums,index,dp):

            if index >= n:
                return 0
            
            if dp[index] != -1:
                return dp[index]

            include = nums[index] + solverec(nums,index+2,dp)
            exclude = 0 + solverec(nums,index+1,dp)
            temp = max(include,exclude)
            dp[index] = temp
            return temp

        index=0
        dp = [-1] * (n+1)
        ans = solverec(nums,index,dp)
        return ans

        