class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (auto& x : nums) {
            unordered_set<int> saw;
            for (int y : x) {
                if (!saw.count(y)) {
                    freq[y]++;
                    saw.insert(y);
                }
            }
        }
        vector<int> ans;
        for (auto& val : freq) {
            if (val.second == n)
                ans.push_back(val.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};