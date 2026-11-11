class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        
        mincost = 0
        minitem = 0
        cost = 0

        mincost = min(costBoth , cost1+cost2)
        minitem = min(need1,need2)

        cost += mincost * minitem

        rem1 = need1 - minitem
        rem2 = need2 - minitem

        cost += rem1 * min(costBoth,cost1)

        cost += rem2 * min(costBoth,cost2)

        return cost
