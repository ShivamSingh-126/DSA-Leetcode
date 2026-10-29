class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        n=len(coins)

        dp = [[-1] * (amount + 1) for _ in range(n)]

        def solve(coins,amount,i):
            if amount == 0:
                return 1

            if i == n:
                return 0

            if dp[i][amount] != -1:
                return dp[i][amount]
            
            if coins[i] > amount:
                dp[i][amount] = solve(coins,amount,i+1)
                return dp[i][amount]
            
            take = solve(coins , amount-coins[i] , i)
            skip = solve(coins , amount , i+1)

            dp[i][amount] =  take+skip

            return dp[i][amount]
        
        return solve(coins,amount,0)