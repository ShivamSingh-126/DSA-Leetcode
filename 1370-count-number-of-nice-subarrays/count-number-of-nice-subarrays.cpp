class Solution {
public:
 int apprx(vector<int>& nums, int k) {
        int l = 0,count = 0, r = 0;

        while (r < nums.size()) {
            if(nums[r]%2==1)
            {
                k--;
            }
            while (k < 0) 
            {
               if (nums[l] % 2 == 1) 
                {
                    k++;
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return apprx(nums, k) - apprx(nums, k - 1);
    }
};