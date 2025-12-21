class Solution {
public:
    int maxindex(vector<int>& row) {
        int n = row.size();
        int maxi = INT_MIN;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (maxi < row[i]) {
                maxi = row[i];
                ans = i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int col = maxindex(mat[mid]);
            int up = (mid > 0) ? mat[mid - 1][col] : INT_MIN;
            int down = (mid < n - 1) ? mat[mid + 1][col] : INT_MIN;
            if (mat[mid][col] > up && mat[mid][col] > down)
                return {mid, col};
            else if (mat[mid][col] < up)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};