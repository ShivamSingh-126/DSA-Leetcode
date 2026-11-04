class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        n=len(coins)

        # def solveRec(coins , amount):
        #     if amount == 0:
        #         return 0
            
        #     mini = float('inf')

        #     for i in range(0,n):
        #         if coins[i] <= amount:
        #             recans = solveRec(coins , amount - coins[i])

        #             if recans != float('inf'):
        #                 mini = min(mini , 1+recans)

        #     return mini

        # def solveMemorisation(coins , amount,dp):
        #     if amount == 0:
        #         return 0

        #     if dp[amount] != -1:
        #         return dp[amount]
            
        #     mini = float('inf')

        #     for i in range(0,n):
        #         if coins[i] <= amount:
        #             recans = solveMemorisation(coins , amount - coins[i],dp)

        #             if recans != float('inf'):
        #                 mini = min(mini , 1+recans)

        #     dp[amount] = mini
        #     return mini

        def solveTabulation(coins , amount):
            
            n = len(coins)

            dp = [float('inf')] * (amount + 1)
            dp[0] = 0

            for i in range(1, amount + 1):
                for j in range(n):
                    if coins[j] <= i:
                        dp[i] = min(dp[i], 1 + dp[i - coins[j]])

            return dp[amount]

            

        # ans = solveRec(coins , amount)
        # if ans == float('inf'):
        #     return -1
        
        # return ans

        # dp = [-1] * (amount+1)
        # ans = solveMemorisation(coins , amount ,dp)

        # if ans == float('inf'):
        #     return -1

        # return ans

        ans = solveTabulation(coins , amount)

        if ans == float('inf'):
            return -1

        return ans