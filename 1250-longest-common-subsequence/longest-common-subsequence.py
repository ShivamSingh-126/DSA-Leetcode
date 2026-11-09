class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # def solveRec(text1,text2,i,j):

        #     if i >= len(text1) or j>= len(text2):
        #         return 0

        #     if text1[i] == text2[j]:
        #         return 1 + solveRec(text1,text2,i+1,j+1)
        #     else:
        #         return max(solveRec(text1,text2,i,j+1),solveRec(text1,text2,i+1,j))


        # def solveMem(text1,text2,i,j,dp):

        #     if i >= len(text1) or j>= len(text2):
        #         return 0

        #     if dp[i][j] != -1:
        #         return dp[i][j]

        #     if text1[i] == text2[j]:
        #         return 1 + solveMem(text1,text2,i+1,j+1,dp)
        #     else:
        #         dp[i][j]= max(solveMem(text1,text2,i,j+1,dp),solveMem(text1,text2,i+1,j,dp))

        #     return dp[i][j]


        def solveTab(text1, text2):
            n = len(text1)
            m = len(text2)

            dp = [[0] * (m + 1) for _ in range(n + 1)]

            for i in range(n - 1, -1, -1):
                for j in range(m - 1, -1, -1):

                    if text1[i] == text2[j]:
                        dp[i][j] = 1 + dp[i + 1][j + 1]
                    else:
                        dp[i][j] = max(dp[i][j + 1], dp[i + 1][j])

            return dp[0][0]


        # return solveRec(text1,text2,0,0)
        # dp = [[-1] * (1002) for _ in range(1002)]
        # return solveMem(text1,text2,0,0,dp)

        return solveTab(text1,text2)