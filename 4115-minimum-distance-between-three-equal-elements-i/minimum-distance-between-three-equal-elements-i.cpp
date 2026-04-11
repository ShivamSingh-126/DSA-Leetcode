class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        /*
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
               for(int k=j+1;k<nums.size();k++)               
               {
                    if(nums[i] == nums[j] && nums[j] == nums[k])
                    {
                        int diff=abs(i-j) + abs(j-k) + abs(k-i);
                        mini=min(mini,diff);
                    } 
               }
            }         
        }
        return (mini == INT_MAX) ? -1 : mini ; 
        */

        int n=nums.size();
        int mini=INT_MAX;
        unordered_map<int,vector<int>>mp;   // number of vector

        for(int k=0;k<n;k++)
        {
            mp[nums[k]].push_back(k);
            
            if(mp[nums[k]].size() >= 3)
            {
                vector<int> & idx=mp[nums[k]];  // index vector

                int len=idx.size();

                int i=idx[len-3];
                // mini=min(mini,2*(k-i));
                mini=min(mini,(k-i)); // instead of doind 2 times mult do at last
            }
        }
        return mini == INT_MAX ? -1 : 2*mini;
    }
};