class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:

        if len(nums) == 1:
            return 1
        inc = dec = 1
        ans = 1

        for i in range(1 , len(nums)):

            if nums[i] > nums[i-1]:
                inc += 1
                dec=1

            elif nums[i] < nums[i-1]:
                dec += 1
                inc=1

            else:
                inc=1
                dec=1

            ans = max(ans,max(inc,dec))

        return ans
