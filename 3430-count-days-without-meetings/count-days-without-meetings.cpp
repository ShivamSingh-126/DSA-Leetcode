class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        int start=0;
        int end=0;
        int off_days=0;

        for(int i=0;i<n;i++)
        {
            if(meetings[i][0] > end)
            {
                off_days += meetings[i][0] - end -1;
            }
            end = max(end,meetings[i][1]);
        }
        if(end < days)
        {
            off_days += days-end;
        }
        return off_days;
    }
};