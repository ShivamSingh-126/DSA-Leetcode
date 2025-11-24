class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int storeval = 0;
        for (auto x : nums) {
            storeval = (storeval * 2 + x) % 5;
            if (storeval == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};