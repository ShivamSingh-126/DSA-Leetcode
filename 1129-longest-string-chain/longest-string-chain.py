class Solution:
    def longestStrChain(self, words: list[str]) -> int:
        
        words.sort(key = len)
        ans=0
        dp={}

        for word in words:
            dp[word] = 1

            for i in range(len(word)):
                prev = word[:i] + word[i+1:]

                if prev in dp:
                    dp[word] = max(dp[word] , dp[prev]+1)

            ans = max(ans , dp[word])


        return ans