class Solution {
public:
    int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) 
    {
        unordered_map<int,int> mp;
        for(auto & point : points)
        {
            int x=point[1];
            mp[x]++;
        }
        long long res=0; // count trapazoid
        long long preHorLine=0;

        for(auto &it:mp)
        {
            long long count=it.second;

            long long totalHorLine= count * (count-1)/2;

            res += totalHorLine * preHorLine;

            preHorLine += totalHorLine;
        }
        return res % M;
    }

};