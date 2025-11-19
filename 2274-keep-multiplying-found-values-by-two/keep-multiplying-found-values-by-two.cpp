class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        /*
        sort(nums.begin(),nums.end());
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == original) {
                original *= 2;
            }
            i++;
        }
        return original;
*/
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(original)) {
            original *= 2;
        }
        return original;
    }
};