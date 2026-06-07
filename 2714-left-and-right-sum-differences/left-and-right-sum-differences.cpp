class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n=nums.size();
        int leftsum=0;
        int sum=0;

        for(int val:nums)
        {
            sum+=val;
        }        
        for(int i=0;i<n;i++)
        {
            int rightsum = sum-leftsum-nums[i];
            int curval=nums[i];

            nums[i] = abs(leftsum - rightsum);
            leftsum += curval;
        }
        return nums;
    }
};