class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        arr=[]

        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i-1]:
                arr.append(nums[i])

        n=len(arr)
        count=0

        for i in range(1,n-1):
            if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
                count += 1
            elif arr[i] < arr[i-1] and arr[i] < arr[i+1]:
                count += 1
        return count if count > 0 else 0
