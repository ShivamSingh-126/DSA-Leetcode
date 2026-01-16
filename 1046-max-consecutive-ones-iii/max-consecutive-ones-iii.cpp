class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        /*
        int n=nums.size(),zero=0,maxlen=0;
        for(int i=0;i<n;i++)
        {
            zero=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==0)
                {
                    zero++;                    
                }
                if(zero<=k)
                {
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
        */
        int maxlen=0,l=0,r=0,zero=0;
        while(r<nums.size())
        {
            if(nums[r]==0) zero++;
            while(zero >k)
            {
                if(nums[l]==0) zero--;
                l++;
            }
            if(zero <=k)
            {
                maxlen=max(maxlen,r-l+1);
                r++;
            }
        }
        return maxlen;
    }
};