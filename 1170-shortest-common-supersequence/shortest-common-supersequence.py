class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        
        m=len(str1)
        n=len(str2)


        # def solveRec(str1,str2,m,n):

        #     if m == 0:
        #         return str2[:n]
        #     if n == 0:
        #         return str1[:m]
            
        #     if str1[m-1] == str2[n-1]:
        #         return  solveRec(str1,str2,m-1,n-1) + str1[m-1]
        #     else:
        #         s1 =  solveRec(str1,str2,m-1,n)
        #         s2 =  solveRec(str1,str2,m,n-1)

        #     if len(s1) < len(s2):
        #         return s1 + str1[m-1]
        #     else:
        #         return s2 + str2[n-1]

        # return solveRec(str1,str2,m,n)

        

        # def solveMem(m,n,dp):

        #     if dp[m][n] is not None:
        #         return dp[m][n]

        #     if m == 0:
        #         return str2[:n]
        #     if n == 0:
        #         return str1[:m]
            
        #     if str1[m-1] == str2[n-1]:
        #         dp[m][n] = solveMem(m-1,n-1,dp) + str1[m-1]
        #     else:
        #         s1 =  solveMem(m-1,n,dp)
        #         s2 =  solveMem(m,n-1,dp)

        #         if len(s1) < len(s2):
        #             dp[m][n] =  s1 + str1[m-1]
        #         else:
        #             dp[m][n] =  s2 + str2[n-1]  

        #     return dp[m][n]


        # dp = [[None] * (n+1) for _ in range(m+1)]
        # return solveMem(m,n,dp)


        dp = [[-1] * (n+1) for _ in range(m+1)]

        def solveMem(m, n):

            if m == 0 or n == 0:
                return 0

            if dp[m][n] != -1:
                return dp[m][n]

            if str1[m-1] == str2[n-1]:
                dp[m][n] = 1 + solveMem(m-1, n-1)

            else:
                dp[m][n] = max(solveMem(m-1, n), solveMem(m, n-1))

            return dp[m][n]

        solveMem(m, n)

        ans = []
        i, j = m, n

        while i > 0 and j > 0:

            if str1[i-1] == str2[j-1]:
                ans.append(str1[i-1])
                i -= 1
                j -= 1

            elif dp[i-1][j] >= dp[i][j-1]:
                ans.append(str1[i-1])
                i -= 1

            else:
                ans.append(str2[j-1])
                j -= 1

        while i > 0:
            ans.append(str1[i-1])
            i -= 1

        while j > 0:
            ans.append(str2[j-1])
            j -= 1

        return ''.join(ans[::-1])