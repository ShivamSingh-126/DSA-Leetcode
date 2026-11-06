class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)

        # def solveRec(index , nums , flag):
        #     if index >= n:
        #         return 0

        #     skip = solveRec(index+1,nums,flag)

        #     val = nums[index]
        #     if flag == False:
        #         val = -val
            
        #     take = solveRec(index+1,nums,not flag) + val

        #     return max(skip , take)


        # def solveMem(index , nums , flag,dp):
        #     if index >= n:
        #         return 0

        #     if dp[index][flag] != -1:
        #         return dp[index][flag]

        #     skip = solveMem(index+1,nums,flag,dp)

        #     val = nums[index]
        #     if flag == False:
        #         val = -val
            
        #     take = solveMem(index+1,nums,not flag,dp) + val
        #     dp[index][flag] =  max(skip , take)

        #     return dp[index][flag]



        def solveTab(nums):
            n=len(nums)
            dp = [[0] * 2 for _ in range(n+1)]

            for index in range(n-1,-1,-1):

                for flag in range(2):

                    skip = dp[index+1][flag]

                    val = nums[index]
                    if flag == False:
                        val = -val
                    
                    take = dp[index+1][not flag] + val
                    dp[index][flag] =  max(skip , take)

            return dp[0][True]



        # return solveRec(0,nums,True)

        # dp = [[-1] * 2 for _ in range(n)]
        # return solveMem(0,nums,True,dp)

        return solveTab(nums)


