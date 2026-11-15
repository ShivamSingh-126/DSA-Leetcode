class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # mp = {}

        # for ch in word1:
        #     mp[ch] = mp.get(ch, 0) + 1

        # for ch in word2:
        #     if ch in mp:
        #         mp[ch] -= 1
        #         if mp[ch] == 0:
        #             del mp[ch]
        #     else:
        #         mp[ch] = 1

        # count=0
        # for key,value in mp.items():
        #     count += value

        # return count


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

        lcs = solveTab(word1, word2)

        return len(word1) + len(word2) - 2 * lcs