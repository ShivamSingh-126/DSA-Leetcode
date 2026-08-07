class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int n=plantTime.size();

        vector<pair<int,int>>ans(n);

        for(int i=0;i<n;i++)
        {
            ans[i] = {plantTime[i],growTime[i]};
        }

        auto lembda = [](pair<int,int>&p1,pair<int,int>&p2)
        {
            return p1.second > p2.second;
        };
        sort(ans.begin(),ans.end(),lembda); // sort according to grow time in descending

        int maxdays = 0;
        int prevdays = 0;

        for(int i=0;i<n;i++)
        {
            int currplanttime = ans[i].first;
            int currgrowtime = ans[i].second;

            prevdays += currplanttime;

            int bloomdays = prevdays + currgrowtime;

            maxdays = max(maxdays,bloomdays);
        }
        return maxdays;
    }
};