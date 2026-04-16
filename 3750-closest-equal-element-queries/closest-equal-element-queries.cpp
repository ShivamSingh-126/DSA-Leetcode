class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size(), -1);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int val = nums[idx];
            vector<int>& chk = mp[val];

            if (chk.size() == 1)
                continue;

            int pos = lower_bound(chk.begin(), chk.end(), idx) - chk.begin();

            int res = INT_MAX;

            // previous (circular)
            int prev = (pos == 0) ? chk.back() : chk[pos - 1];
            int d1 = abs(idx - prev);
            res = min(res, min(d1, n - d1));

            // next (circular)
            int next = (pos == chk.size() - 1) ? chk[0] : chk[pos + 1];
            int d2 = abs(idx - next);
            res = min(res, min(d2, n - d2));

            ans[i] = res;
        }

        return ans;
    }
};