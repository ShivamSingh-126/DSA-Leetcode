class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        /*

        //  Brute force

        vector<vector<int>> ans;
        set<vector<int>>s;      //set unique triplet

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());

                        if(s.find(trip)==s.end())
                        {
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
        */
        /*
        //  Brute Approach 
        set<vector<int>> uniquetrip;
        for(int i=0;i<n;i++)
        {
            set<int>s;
            for(int j=i+1;j<n;j++)
            {
                int third=-(nums[i]+nums[j]);
                if(s.find(third)!=s.end())
                {
                    vector<int>trip={nums[i],nums[j],third};
                    sort(trip.begin(),trip.end());
                    uniquetrip.insert(trip);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniquetrip.begin(),uniquetrip.end());
        return ans;
        */
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i>0 &&nums[i]==nums[i-1])continue;   // not repeat for same value
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {   // if sum==0 then push into ans
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1])j++;    //not repeat for same value
                }
            }
        }
        return ans;
    }
};