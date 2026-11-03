class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        # ans=0

        # def solvemem(nums,index,dp):

        #     if index >= n:
        #         return 0
            
        #     if dp[index] != -1:
        #         return dp[index]

        #     include = nums[index] + solvemem(nums,index+2,dp)
        #     exclude = 0 + solvemem(nums,index+1,dp)
        #     temp = max(include,exclude)
        #     dp[index] = temp
        #     return temp


        def solveTab(nums):
            # step 1 -- create dp list
            dp = [-1]*(n+1)
            # step 2 -- analyse base case and fill dp
            dp[n] = 0
            # step 3 -- reverse the flow loop and copy from memorisation
            for i in range(n-1 , -1 , -1):
                temp=0
                if i+2 <= n:
                    temp = dp[i+2]

                include = nums[i] + temp
                exclude = 0 + dp[i+1]
                dp[i] = max(include,exclude)

            # analyse the index and return ans 
            return dp[0]

        index=0
        # dp = [-1] * (n+1)
        # ans = solvemem(nums,index,dp)
        # return ans

        ans = solveTab(nums)

        return ans