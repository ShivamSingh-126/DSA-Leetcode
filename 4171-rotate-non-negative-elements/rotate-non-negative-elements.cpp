class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> str;
        for (int val : nums) {
            if (val >= 0) {
                str.push_back(val);
            }
        }
        int m=str.size();
        if (m == 0)
        return nums;
        k = k % m;
        reverse(str.begin(), str.begin()+k);
        reverse(str.begin()+k, str.end());
        reverse(str.begin(), str.end());

        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = str[idx++];
            }
        }
        return nums;
    }
};