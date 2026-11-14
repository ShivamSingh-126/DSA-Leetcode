class Solution:
    def minCut(self, s: str) -> int:
        # n = len(s)

        # def ispalindrome(s, i, j):
        #     while i <= j:
        #         if s[i] != s[j]:
        #             return False

        #         i += 1
        #         j -= 1

        #     return True

        # def solveRec(s,i,j):
        #     if i >= j:
        #         return 0

        #     if ispalindrome(s,i,j):
        #         return 0

        #     cut=float('inf')
        #     for k in range(i,j-1+1):
        #         temp = 1 + solveRec(s,i,k) + solveRec(s,k+1,j)
        #         cut = min(cut,temp)

        #     return cut

        # return solveRec(s,0,n-1,dp)

        # def solveMem(s, i, j, dp):
        #     if i >= j or ispalindrome(s, i, j):
        #         return 0

        #     if dp[i][j] != -1:
        #         return dp[i][j]

        #     cut = float("inf")
        #     for k in range(i, j):
        #         if ispalindrome(s, i, k):
        #             temp =1 + solveMem(s, k + 1, j, dp)
        #             cut = min(cut, temp)

        #     dp[i][j] = cut
        #     return dp[i][j]

        # dp = [[-1] * (n) for _ in range(n)]
        # return solveMem(s, 0, n - 1, dp)


        n = len(s)

        if n == 0:
            return 0

        # Precompute palindrome table
        pal = [[False] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 2 or pal[i+1][j-1]):
                    pal[i][j] = True

        # DP: minimum palindrome partitions
        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        for end in range(n):
            for start in range(end + 1):
                if pal[start][end]:
                    dp[end + 1] = min(
                        dp[end + 1],
                        dp[start] + 1
                    )

        return dp[n] - 1

