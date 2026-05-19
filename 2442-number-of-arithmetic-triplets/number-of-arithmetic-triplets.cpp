class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int count=0;
        unordered_set<int>st(nums.begin(),nums.end());

        for(auto val : nums)
        {
            if(st.count(val+diff)&& st.count(val+2*diff))
            count++;
        }
        return count;
    }
};