class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        /*
        int n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int j=i;j<n;j++)
            {
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);

                long long cost=1ll*(maxi-mini)*(j-i+1);
                if(cost <= k)  count++;               
            }
        }
        return count;
        */

        int n=nums.size();
        multiset<int>st;
        int i=0,j=0;
        long long ans=0;

        while(j<n)
        {
            st.insert(nums[j]);

            while(j>i && 1ll* ((*st.rbegin())-(*st.begin()))*st.size()>k)
            {
                st.erase(st.find(nums[i]));
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};