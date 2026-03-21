class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) 
    {
        int str=x;
        int endr=x+k-1;
        int strc=y;
        int endc=y+k-1;

        for(int i=str;i<=endr;i++)
        {
            for(int j=strc;j<=endc;j++)
            {
                swap(grid[i][j],grid[endr][j]);
            }
            endr--;
        }
        return grid;
    }
};