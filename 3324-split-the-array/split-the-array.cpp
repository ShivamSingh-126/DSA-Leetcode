class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) 
    {
        unordered_map<int,int>mpp;

        for(int val:nums)
        {
           mpp[val]++;
           if(mpp[val] > 2)
           {
            return false;
           }
        }
        return true;
    }
};