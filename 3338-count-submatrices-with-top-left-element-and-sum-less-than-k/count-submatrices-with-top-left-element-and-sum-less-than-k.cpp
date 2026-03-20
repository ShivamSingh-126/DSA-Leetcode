class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> sum(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum[i][j]=grid[i][j];

                if(i-1 >=0)
                {
                    sum[i][j] +=sum[i-1][j];
                }
               
                if(j-1 >=0)
                {
                    sum[i][j] +=sum[i][j-1];
                }

                if(i-1 >=0 && j-1 >=0)
                {
                    sum[i][j] -=sum[i-1][j-1];
                }

                if(sum[i][j] <= k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};