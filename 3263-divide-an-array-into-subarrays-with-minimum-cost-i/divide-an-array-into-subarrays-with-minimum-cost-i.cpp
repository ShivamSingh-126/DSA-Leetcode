class Solution {
public:
    int minimumCost(vector<int>& nums) 
    {
        int f=nums[0];
        int m1=INT_MAX,m2=INT_MAX;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] < m1)
            {
                m2=m1;
                m1=nums[i];
            }
            else if(nums[i] < m2)
            {
                m2=nums[i];
            }
        }
        return f+m1+m2;
    }
};