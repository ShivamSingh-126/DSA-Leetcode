class Solution:
    def countSubarrays(self, nums: list[int], minK: int, maxK: int) -> int:
        count = 0
        left = -1
        maxi = -1
        mini = -1

        # for i in range(len(nums)):
        #     if nums[i] < minK or nums[i] > maxK:
        #         left = i

        #     count += i-left

        for i in range(len(nums)):
            if nums[i] >= minK and nums[i] <= maxK:
                count += i-left

            else:
                left = i

        return count