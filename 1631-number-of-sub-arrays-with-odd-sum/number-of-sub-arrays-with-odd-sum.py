class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        mod = 10 ** 9 + 7 
        n=len(arr)
        prefix = [0] * n
        prefix[0] = arr[0]

        for i in range(1,n):
            prefix[i] = prefix[i-1] + arr[i]

        count=0
        even=1
        odd=0

        for i in range(n):
            if prefix[i] % 2 == 0:
                count = (count+odd) % mod
                even+= 1
            
            else:
                count = (count + even) % mod
                odd += 1

        return count
