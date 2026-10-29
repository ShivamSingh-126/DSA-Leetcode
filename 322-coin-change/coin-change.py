class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:

        # def solRec(coin,amount):
        #     if amount == 0:
        #         return 0
        #     if amount < 0:
        #         return float('inf')

        #     mini = float('inf')

        #     for i in range(len(coins)):
        #         ans = solRec(coins , amount-coins[i])
        #         if ans != float('inf'):
        #             mini = min(mini,1+ans)
            
        #     return mini

        def solMem(coin,amount,dp):
            if amount == 0:
                return 0

            if amount < 0:
                return float('inf')

            if dp[amount] != -1:
                return dp[amount]

            mini = float('inf')

            for i in range(len(coins)):
                ans = solMem(coins , amount-coins[i],dp)
                if ans != float('inf'):
                    mini = min(mini,1+ans)

            dp[amount] = mini
            
            return mini
        
        # ans = solRec(coins,amount)
        # if ans == float('inf'):
        #     return -1

        dp = [-1] * (amount+1)
        
        ans = solMem(coins,amount,dp)

        if ans == float('inf'):
            return -1
        
        return ans

