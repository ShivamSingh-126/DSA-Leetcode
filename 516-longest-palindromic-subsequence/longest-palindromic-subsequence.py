class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)
        # def solveRec(s,i,j):
        #     if i > j:
        #         return 0

        #     if i == j:
        #         return 1

        #     if s[i] == s[j]:
        #         return 2 + solveRec(s,i+1,j-1)
            
        #     else:
        #         return max(solveRec(s,i+1,j),solveRec(s,i,j-1))

        # return solveRec(s,0,len(s)-1)

        def solveMem(s,i,j,dp):
            if i > j:
                return 0

            if i == j:
                return 1

            if dp[i][j] != -1:
                return dp[i][j]

            if s[i] == s[j]:
                dp[i][j] = 2 + solveMem(s,i+1,j-1,dp)
            
            else:
                dp[i][j] =  max(solveMem(s,i+1,j,dp),solveMem(s,i,j-1,dp))

            return dp[i][j]

        
        dp = [[-1] * n for _ in range(n)]
        return solveMem(s,0,n-1,dp)