class Solution:
    def minInsertions(self, s: str) -> int:
        
        n = len(s)

        # def solveMem(i,j,s,dp):
        #     if i >= j:
        #         return 0
            
        #     if dp[i][j] != -1:
        #         return dp[i][j]

        #     if s[i] == s[j]:
        #         dp[i][j] = solveMem(i+1,j-1,s,dp)

        #     else:
        #         dp[i][j] =1 + min(solveMem(i+1,j,s,dp),solveMem(i,j-1,s,dp))

        #     return dp[i][j]

        def solveTab(s):
            dp = [[0]*n for _ in range(n)]

            for l in range(2,n+1):
                for i in range(n-l+1):
                    j=i+l-1

                    if s[i] == s[j]:
                        dp[i][j] = dp[i+1][j-1]
                    else:
                        dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1])

            return dp[0][n-1]

        # dp = [[-1]*501 for _ in range(501)]
        # return solveMem(0,len(s)-1,s,dp)

        return solveTab(s)