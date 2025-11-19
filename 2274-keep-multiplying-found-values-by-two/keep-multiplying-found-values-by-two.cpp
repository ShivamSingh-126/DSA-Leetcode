class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == original) {
                original *= 2;
            }
            i++;
        }
        return original;
    }
};