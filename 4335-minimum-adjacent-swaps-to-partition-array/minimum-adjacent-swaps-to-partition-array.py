class Solution:
    def minAdjacentSwaps(self, nums: list[int], a: int, b: int) -> int:
        
        middle = large = ans = 0
        mod = 10**9+7
        for val in nums:
            if val < a :
                ans  = (ans + middle + large) % mod
            elif val <= b :
                ans = (ans + large) % mod
                middle+=1
            else:
                large +=1

        return ans
