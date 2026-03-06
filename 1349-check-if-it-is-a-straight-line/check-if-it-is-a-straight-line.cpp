class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n=coordinates.size();
        //    [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]

        int dy=coordinates[1][1] - coordinates[0][1];
        int dx=coordinates[1][0] - coordinates[0][0];

        for(int i=2;i<n;i++)
        {
            int dyi=coordinates[i][1] - coordinates[0][1];
            int dxi=coordinates[i][0] - coordinates[0][0];

        // slope of straight line is same so we check slope
        // here we cross mult each other to avoid 0 in denominator 
            if(dyi * dx != dxi * dy)  return false;
        }
        return true;
    }
};