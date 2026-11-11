class Solution:
    def countSubstrings(self, s: str) -> int:
        
        n=len(s)

        def checkPalindrome(s,i,j,dp):
            if i >= j:
                return True

            if dp[i][j] != -1:
                return dp[i][j]
            
            if s[i] == s[j]:
                dp[i][j] =  checkPalindrome(s,i+1,j-1,dp)

            else:
                dp[i][j] = False

            return dp[i][j]

        count=0
        dp = [[-1] * n for _ in range(n)]
        for i in range(n):
            for j in range(i,n):
                if checkPalindrome(s,i,j,dp):
                    count += 1

        return count