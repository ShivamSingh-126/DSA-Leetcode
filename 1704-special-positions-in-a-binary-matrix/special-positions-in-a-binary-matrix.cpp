class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        /*
        int count=0;
        int m=mat.size();
        int n=mat[0].size();

        for(int row=0;row<m ;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col] == 0) continue;

                bool flag=true;
                // check row
                for(int r=0;r<m;r++)
                {
                    if(r != row && mat[r][col] == 1)
                    {
                        flag=false;
                        break;
                    }
                }
                // check column
                for(int c=0;c<n;c++)
                {
                    if(c != col && mat[row][c] == 1)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag == true) count++;
            }
        }
        return count;
        */
        int m=mat.size();
        int n=mat[0].size();

        vector<int> rowcount(m,0);
        vector<int> colcount(n,0);

        for(int row=0;row<m ;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col] == 1)
                {
                    rowcount[row]++;
                    colcount[col]++;
                }
            }
        }

        int count=0;
        for(int row=0;row<m ;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(mat[row][col] == 0) continue;

                if(rowcount[row] == 1 && colcount[col]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};