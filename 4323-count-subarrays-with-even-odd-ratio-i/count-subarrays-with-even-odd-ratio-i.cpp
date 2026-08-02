class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) 
    {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            int ec=0;
            int oc=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j] % 2 != 0)
                {
                    oc++;
                }
                else
                {
                    ec++;
                }

                if(oc > 0 && ec*b <= a*oc)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};