class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n=nums.size();
        int maxi=-1;
        vector<int>pregcd(n);

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            pregcd[i] = __gcd(maxi,nums[i]);
        }
        sort(pregcd.begin(),pregcd.end());
        long long ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+= __gcd(pregcd[i],pregcd[n-i-1]);
        }
        return ans;
    }
};