class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==3)  return nums[0]*nums[1]*nums[2];

        int gr=INT_MIN;
        int sgr=INT_MIN;
        int tgr=INT_MIN;

        int s=INT_MAX;
        int ss=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(nums[i] >= gr)
            {
                tgr = sgr;
                sgr = gr;
                gr=nums[i];
            }
            else if(nums[i] >= sgr)
            {
                tgr = sgr;
                sgr = nums[i];
            }
            else if(nums[i] >= tgr)
            {
                tgr = nums[i];
            }
            
            if(nums[i] <= s)
            {
                ss=s;
                s=nums[i];
            }
            else if(nums[i] <= ss)
            {
                ss=nums[i];
            }
        }
        return max(gr*sgr*tgr,gr*ss*s);
    }
};