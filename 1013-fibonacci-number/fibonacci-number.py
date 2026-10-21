class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """


        def topDown(n,dp):
            if n==0 or n==1:
                return n
            #Step 3 check if ans already exist
            if dp[n] != -1: 
                return dp[n]
            
            # step 2 Replace ans with dp[n]
            dp[n]=topDown(n-1,dp) + topDown(n-2,dp)
            return dp[n]

        dp = [-1] * (n+1)   # step 1 create dp array
        return topDown(n,dp)
        