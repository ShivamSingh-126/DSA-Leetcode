# class Solution:
#     def longestStrChain(self, words: list[str]) -> int:
        
#         words.sort(key = len)
#         ans=0
#         dp={}

#         for word in words:
#             dp[word] = 1

#             for i in range(len(word)):
#                 prev = word[:i] + word[i+1:]

#                 if prev in dp:
#                     dp[word] = max(dp[word] , dp[prev]+1)

#             ans = max(ans , dp[word])


#         return ans


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=len)

        n = len(words)
        dp = [1] * n
        ans = 1

        for i in range(n):
            for j in range(i):
                if len(words[i]) == len(words[j]) + 1:
                    if self.check(words[j], words[i]):
                        dp[i] = max(dp[i], dp[j] + 1)

            ans = max(ans, dp[i])

        return ans

    def check(self, a, b):
        i = j = 0

        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                i += 1
            j += 1

        return i == len(a)