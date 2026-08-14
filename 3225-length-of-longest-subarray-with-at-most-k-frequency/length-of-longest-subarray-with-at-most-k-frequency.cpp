class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int i=0,j=0;

        int max_len = 0;
        while(j < n)
        {
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k)
            {
                mpp[nums[i]]--;
                i++;
            }
            max_len = max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};