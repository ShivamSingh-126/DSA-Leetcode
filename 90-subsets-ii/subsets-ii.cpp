class Solution {
public:
    void solve(vector<int>& nums, int idx,set<vector<int>>& st,
 vector<int>& temp) 
               {
        if (idx == nums.size()) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[idx]); // include
        solve(nums, idx + 1, st, temp);
        temp.pop_back(); // Exclude
        solve(nums, idx + 1, st, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> temp;

        solve(nums, 0, st, temp);
        return vector<vector<int>>(st.begin(),st.end());
    }
};