class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i;
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> temp;

        while (srow <= erow && scol <= ecol) {
            // top
            for (i = scol; i <= ecol; i++) {
                temp.push_back(matrix[srow][i]);
            }
            // right
            for (i = srow + 1; i <= erow; i++) {
                temp.push_back(matrix[i][ecol]);
            }
            // bottom
            for (i = ecol - 1; i >= scol; i--) {
                if (srow == erow) {
                    break;
                }
                temp.push_back(matrix[erow][i]);
            }
            // left
            for (i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) {
                    break;
                }
                temp.push_back(matrix[i][scol]);
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return temp;
    }
};