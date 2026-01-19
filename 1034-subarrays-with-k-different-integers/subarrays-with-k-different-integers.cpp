class Solution {
public:
int atmost(vector<int>& nums, int k)
{
    int l=0,r=0,count=0;
        unordered_map<int,int>mp;
        while(r<nums.size())
        {
            mp[nums[r]]++;
            while(mp.size() > k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        /*
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {
            map<int,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[nums[j]]++;
                if(mp.size()==k)
                {
                    count++;
                }
                else if(mp.size() > k) break;
            }
        }
        return count;
        */
        return atmost(nums,k) - atmost(nums,k-1);
    }
};