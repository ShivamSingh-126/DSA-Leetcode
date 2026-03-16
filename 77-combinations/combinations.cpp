class Solution {
public:
    void solve(int n, int k,vector<vector<int>> &ans, vector<int> &temp,int start)
    {
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(start > n)   return;

        //include
        temp.push_back(start);
        solve(n,k-1,ans,temp,start+1);
        //exclude
        temp.pop_back();
        solve(n,k,ans,temp,start+1);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(n,k,ans,temp,1);
        return ans;
    }
};