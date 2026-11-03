class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        ans=0

        def solvemem(nums,index,dp):

            if index >= n:
                return 0
            
            if dp[index] != -1:
                return dp[index]

            include = nums[index] + solvemem(nums,index+2,dp)
            exclude = 0 + solvemem(nums,index+1,dp)
            temp = max(include,exclude)
            dp[index] = temp
            return temp

        index=0
        dp = [-1] * (n+1)
        ans = solvemem(nums,index,dp)
        return ans

        