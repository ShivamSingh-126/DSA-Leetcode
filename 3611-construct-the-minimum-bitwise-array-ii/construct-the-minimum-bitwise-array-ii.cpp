class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        /*
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            bool chk = false;
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    ans.push_back(j);
                    chk = true;
                    break;
                }
            }
            if (!chk)
                ans.push_back(-1);
        }
        return ans;
        */
        vector<int> ans;
        for (int num : nums) {
            if (num % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            int x = num;
            for (int j = 0; j < 32; j++) {
                if (((num >> j) & 1) == 0) {
                    x = num ^ (1 << (j - 1));
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};