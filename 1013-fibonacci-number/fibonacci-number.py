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


        def bottomUp(n):
            #Step 1 create dp list
            dp = [-1] * (n+1)

            #Step 2 Observe base case
            dp[0]=0
            if n==0:
                return dp[0]
            dp[1]=1
            if n==1:
                return dp[1]

            
            #Step 3 run loop
            for i in range(2,n+1):
                dp[i]=dp[i-1]+dp[i-2]

            return dp[n]


        
        #return topDown(n,dp)
        return bottomUp(n)
        