class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        // Brute force
/*
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(abs(i-j)<=indexDiff && abs(nums[i]-nums[j]) <=valueDiff)
                {
                    return true;
                }
            }
        }
        return false;
*/
        set<int> st(nums.begin(),nums.end());
        if(valueDiff==0 && nums.size()==st.size())  return false;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1; j<i+1+indexDiff; j++)
            {
                if(j>=nums.size())  break;
                if(abs((long long)nums[i]-(long long)nums[j]) <=valueDiff)
                {
                    return true;
                }
            }
        }
        return false;
    }
};