class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,int cStart) 
    {
        vector<vector<int>> res;
        int total = rows * cols;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        res.push_back({rStart, cStart});
        int count = 1;

        int step=1;
        int index=0;
        while(count<total)
        {
            for(int times=0;times<2;times++)
            {
                int dr=directions[index%4][0];
                int dc=directions[index%4][1];
                for(int i=0;i<step;i++)
                {
                    rStart+=dr;
                    cStart+=dc;
                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                    {
                        res.push_back({rStart, cStart});
                        count++;
                    }
                }
                index++;
            }
            step++;
        }
        return res;
    }
};