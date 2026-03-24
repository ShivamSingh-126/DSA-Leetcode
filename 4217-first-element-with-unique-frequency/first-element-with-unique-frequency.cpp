class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) 
    {
        unordered_map<int,int>freq;
        for(auto& val:nums)
        {
            freq[val]++;
        }
        unordered_map<int,int>freqcnt;
        for(auto val : freq)
        {
            freqcnt[val.second]++;
        }
        for(auto val : nums)
        {
            if(freqcnt[freq[val]]==1)  return val;
        }
        return -1;
    }
};