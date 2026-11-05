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

        def solveMemorisation(index,amount,dp):
            if amount == 0:
                return 1

            if index == n:
                return 0

            if dp[index][amount] != -1:
                return dp[index][amount]
            
            notpick = solveMemorisation(index+1,amount,dp)

            pick = 0 
            if amount >= coins[index]:
                pick = solveMemorisation(index , amount-coins[index],dp)

            dp[index][amount] =  pick + notpick
            return dp[index][amount]


        dp = [[-1] * (amount + 1) for _ in range(n)]
        return solveMemorisation(0,amount,dp)
