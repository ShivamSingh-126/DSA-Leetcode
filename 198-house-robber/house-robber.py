class Solution(object):
    def solve(self,nums,i,n,t):
        if i >= n:
            return 0
        
        if t[i] != -1:
            return t[i]
        
        steal = nums[i]+self.solve(nums,i+2,n,t)
        skip = self.solve(nums,i+1,n,t)

        t[i] = max(steal,skip)
        return t[i]
    
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        t=[-1]*n
        return self.solve(nums,0,n,t)
        