class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) 
    {
        /*
        int n=nums.size();
        vector<long long>ans;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                if(nums[i] == nums[j])
                {
                    sum+=abs(i-j);
                }
            }
            ans.push_back(sum);
        }
        return ans;
        */
        int n=nums.size();
        vector<ll>arr(n,0);

        unordered_map<int,ll>indexsum;
        unordered_map<int,ll>indexcount;

        //left - Right
        for(int i=0;i<n;i++)
        {
            ll freq=indexcount[nums[i]];
            ll sum=indexsum[nums[i]];

            arr[i] +=freq*i - sum;

            indexsum[nums[i]]+=i;
            indexcount[nums[i]]+=1;
        }
        indexsum.clear();
        indexcount.clear();

        // Right - left
        for(int i=n-1;i>=0;i--)
        {
            ll freq=indexcount[nums[i]];
            ll sum=indexsum[nums[i]];

            arr[i] +=sum - freq*i;

            indexsum[nums[i]]+=i;
            indexcount[nums[i]]+=1;
        }
        return arr;
    }
};