class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> fst, sec, count;
        for (int i = 0; i < nums.size(); i++) {
            if (fst.count(nums[i]) == 0)
                fst[nums[i]] = i;
            sec[nums[i]] = i;
            count[nums[i]]++;
        }
        int maxi = 0, n = nums.size();
        for (auto x : count)
            maxi = max(maxi, x.second);
        for (auto val : count) {
            if (val.second == maxi) {
                n = min(n, sec[val.first] - fst[val.first] + 1);
            }
        }
        return n;
    }
};