class Solution:
    def minOperations(self, nums: list[int], locked: list[int], k: int) -> int:
        n = len(nums)

        diff = [0] * (n+1)
        swap = 0

        for i in range(n):
            for j in range(i+1,n):
                if nums[i] > nums[j]:
                    swap += 1

                    diff[i] += 1
                    diff[j+1] -= 1

        unlock = 0
        active = 0

        for i in range(n):
            active += diff[i]

            if active > 0 and locked[i] == 1:
                unlock +=1

        if unlock > k:
            return -1

        return swap + unlock
        
