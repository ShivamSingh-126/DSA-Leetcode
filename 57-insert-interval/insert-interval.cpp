class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        vector<vector<int>> res;

        for(int i=1;i<n;i++)
        {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= start2)  // merge hoga
            {
                end1 = max(end1,end2);
                continue;
            }
            res.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1,end1});
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int start;
        int n=intervals.size();
        bool clip = false;
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            start = intervals[i][0];
            if(clip == false && start >= newInterval[0])
            {
                res.push_back(newInterval);
                clip = true;
            }
            res.push_back(intervals[i]);
        }
        if(clip == false)
        {
            res.push_back(newInterval);
        }
        return merge(res);
    }
};