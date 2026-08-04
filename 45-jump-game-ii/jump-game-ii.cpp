class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        int step=0,l=0,r=0;
        while(r  < n-1)
        {
            int farth=0;
            for(int i=l;i<=r;i++)
            {
                farth = max(i+nums[i],farth);   // max distance where we reach
            }
            l=r+1;
            step = step+1;
            r=farth;
        }
        return step;
    }
};