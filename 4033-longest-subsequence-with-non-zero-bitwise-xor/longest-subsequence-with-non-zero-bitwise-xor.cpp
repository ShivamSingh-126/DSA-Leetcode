class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int n=nums.size();
        int res_xor = 0;
        int zero_found = true;

        for(int &val : nums)
        {
            res_xor = (res_xor ^ val);
            if(val != 0)
            {
                zero_found =false;
            }
        }
        if(zero_found == true)
        {
            return 0;
        }

        return res_xor == 0 ? n-1 : n;
    }
};