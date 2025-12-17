class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int resultsum = nums[0] + nums[1] + nums[2];
        int miniff = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
                int targetdiiff = abs(sum - target);
                if (targetdiiff < miniff) {
                    resultsum = sum;
                    miniff = targetdiiff;
                }
            }
        }
        return resultsum;
    }
};