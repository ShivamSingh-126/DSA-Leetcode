class Solution(object):
    # def solve(self,nums,i,n,t):
    #     if i >= n:
    #         return 0
        
    #     if t[i] != -1:
    #         return t[i]
        
    #     steal = nums[i]+self.solve(nums,i+2,n,t)
    #     skip = self.solve(nums,i+1,n,t)

    #     t[i] = max(steal,skip)
    #     return t[i]
    
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # n=len(nums)
        # t=[-1]*n
        # return self.solve(nums,0,n,t)

        # n=len(nums)
        # t=[0]*(n+1)

        # if n==0:
        #     return nums[0]

        # t[0] = 0
        # t[1]=nums[0]

        # for i in range(2,n+1):
        #     steal = nums[i-1]+t[i-2]
        #     skip = t[i-1]

        #     t[i] = max(steal,skip)

        # return t[n]

        n=len(nums)
        temp=0

        if n==0:
            return 0
        if n==1:
            return nums[0]

        prevprev = 0
        prev=nums[0]

        for i in range(2,n+1):
            steal = nums[i-1]+prevprev
            skip = prev

            temp = max(steal,skip)

            prevprev=prev
            prev=temp

        return temp
        
        