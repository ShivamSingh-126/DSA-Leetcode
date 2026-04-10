class Solution {
public:
    int ans=INT_MIN;
    int m;
    void backtrack(int idx,int count,int n,vector<int> &result,vector<vector<int>>& requests)
    {
        if(idx >= m)
        {
            bool allzero=true;

            for(int &x : result)
            {
                if(x != 0)
                {
                    allzero=false;
                    break;
                }
            }
            if(allzero == true)
            {
                ans=max(ans,count);
            }
            return;
        }
        int from=requests[idx][0];
        int to=requests[idx][1];

        result[from]--;
        result[to]++;
        backtrack(idx+1,count+1,n,result,requests);

        result[from]++;
        result[to]--;
        backtrack(idx+1,count,n,result,requests);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        m=requests.size();
        vector<int>result(n,0);

        backtrack(0,0,n,result,requests);
        return ans;
    }
};