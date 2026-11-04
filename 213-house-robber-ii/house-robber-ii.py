class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
      
        if n == 1:
            return nums[0]

        def solvemem(start,end,dp):
            
            if start > end:
                return 0

            #case 3 Check in DP
            if dp[start] != -1:
                return dp[start]

            include = nums[start] + solvemem(start+2 , end , dp)
            exclude = 0 + solvemem(start+1,end,dp)

            # Case 2 store ans in DP
            dp[start] = max(include,exclude)
            return dp[start]
        

        # Case 1 create DP
        dp1 = [-1] * (n)
        dp2 = [-1] * (n)

        case1 = solvemem(0,n-2,dp1)
        case2  = solvemem(1,n-1,dp2)

        return max(case1,case2)

