class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n=nums.size();
        vector<int>temp(n,-1);
        temp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i] == -1)  continue;

            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[i]-nums[j])<=target)
                {
                    temp[j]=max(temp[j],temp[i]+1);
                }
            }
        }
        return temp[n-1];
    }
};