class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate = -1, missing = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                duplicate = nums[i];
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!binary_search(nums.begin(), nums.end(), i)) {
                missing = i;
                break;
            }
        }
        return {duplicate, missing};
    }
};