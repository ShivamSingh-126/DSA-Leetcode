class Solution {
public:
    void solve(vector<int>& nums, int idx,vector<vector<int>>& ans,
 vector<int>& temp) 
               {
                /*
        if (idx == nums.size()) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[idx]); // include
        solve(nums, idx + 1, st, temp);
        temp.pop_back(); // Exclude
        solve(nums, idx + 1, st, temp);
        */
        ans.push_back(temp);
        for (int i=idx;i< nums.size();i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]); // include
            solve(nums, i + 1, ans, temp);
            temp.pop_back(); // Exclude
            // return;
        }        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> temp;

        solve(nums, 0, st, temp);
        return vector<vector<int>>(st.begin(),st.end());
        */
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums,0, ans, temp);
        return ans;
    }
};