class Solution {
public:
    int m,n,Nobs,result;   //nonobstacles
    vector<vector<int>>directions={{1,0},{-1,0},{0,-1},{0,1}};  // DULR
    void backtrack(vector<vector<int>>& grid,int count,int i,int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1)
        {
            return;
        }
        if(grid[i][j] == 2)
        {
            if(count == Nobs)   //NonObstacle Path
            {
                result++;
            }
            return;
        }
        int store=grid[i][j];
        grid[i][j] = -1;

        for(vector<int>&dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backtrack(grid,count+1,new_i,new_j);
        }

        grid[i][j]=store;
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        result=0;
        Nobs=0;

        int s_x=0,s_y=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    Nobs++;
                }
                if(grid[i][j] == 1)
                {
                    s_x=i,s_y=j;    // Starting X,Starting Y
                }
            }
        }
        Nobs+=1;

        int count=0;

        backtrack(grid,count,s_x,s_y);
        return result;
    }
};