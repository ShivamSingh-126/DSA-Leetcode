class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        
        n= len(coins)

        # def solveRec(index,amount):
        #     if amount == 0:
        #         return 1

        #     if index == n:
        #         return 0
            
        #     notpick = solveRec(index+1,amount)

        #     pick = 0 
        #     if amount >= coins[index]:
        #         pick = solveRec(index , amount-coins[index])

        #     return pick + notpick

        # def solveMemorisation(index,amount,dp):
        #     if amount == 0:
        #         return 1

        #     if index == n:
        #         return 0

        #     if dp[index][amount] != -1:
        #         return dp[index][amount]
            
        #     notpick = solveMemorisation(index+1,amount,dp)

        #     pick = 0 
        #     if amount >= coins[index]:
        #         pick = solveMemorisation(index , amount-coins[index],dp)

        #     dp[index][amount] =  pick + notpick
        #     return dp[index][amount]


        def solveTabulation(index, amount):
            dp = [[0] * (amount + 1) for _ in range(n)]

            # Base case
            for i in range(n):
                dp[i][0] = 1

            for t in range(amount + 1):
                if t % coins[0] == 0:
                    dp[0][t] = 1

            for index in range(1, n):
                for amt in range(amount + 1):

                    notpick = dp[index - 1][amt]

                    pick = 0
                    if amt >= coins[index]:
                        pick = dp[index][amt - coins[index]]

                    dp[index][amt] = pick + notpick

            return dp[n - 1][amount]


        # dp = [[-1] * (amount + 1) for _ in range(n)]
        return solveTabulation(0,amount)
