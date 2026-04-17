class Solution {
public:
    int opposite(int num)
    {
        int sum=0;
        while(num > 0)
        {
            sum=sum*10+num % 10;
            num /= 10;
        }
        return sum;
    }
    int minMirrorPairDistance(vector<int>& nums) 
    {
        int n=nums.size();
        int mini=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i]))
            {
                mini=min(mini,abs(i-mp[nums[i]]));
            }
            mp[opposite(nums[i])] = i;
        }
        
        
        return mini == INT_MAX ? -1 : mini;
    }
};