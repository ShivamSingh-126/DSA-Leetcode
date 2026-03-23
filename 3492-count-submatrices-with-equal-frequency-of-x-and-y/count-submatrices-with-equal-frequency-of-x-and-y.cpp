class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> gridsumX(m,vector<int>(n,0));
        vector<vector<int>> gridsumY(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                gridsumX[i][j]=(grid[i][j] == 'X');
                gridsumY[i][j]=(grid[i][j] == 'Y');

                if(i-1 >=0)
                {
                    gridsumX[i][j] +=gridsumX[i-1][j];
                    gridsumY[i][j] +=gridsumY[i-1][j];
                }
               
                if(j-1 >=0)
                {
                    gridsumX[i][j] +=gridsumX[i][j-1];
                    gridsumY[i][j] +=gridsumY[i][j-1];
                }

                if(i-1 >=0 && j-1 >=0)
                {
                    gridsumX[i][j] -=gridsumX[i-1][j-1];
                    gridsumY[i][j] -=gridsumY[i-1][j-1];
                }

                if(gridsumX[i][j] == gridsumY[i][j] && gridsumX[i][j] > 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};