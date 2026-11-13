class Solution:
    def minInsertions(self, s: str) -> int:
        
        def solveMem(i,j,s,dp):
            if i >= j:
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]

            if s[i] == s[j]:
                dp[i][j] = solveMem(i+1,j-1,s,dp)

            else:
                dp[i][j] =1 + min(solveMem(i+1,j,s,dp),solveMem(i,j-1,s,dp))

            return dp[i][j]

        dp = [[-1]*501 for _ in range(501)]
        return solveMem(0,len(s)-1,s,dp)