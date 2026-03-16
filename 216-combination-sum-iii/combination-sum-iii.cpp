class Solution {
public:
    void solve(int n, int k,vector<vector<int>> &ans, vector<int> &temp,int start)
    {
        if(n==0 && k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(n < 0 || k==0)  return;
        for(int i=start;i<=9;i++)
        {
            temp.push_back(i);
            solve(n-i,k-1,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(n,k,ans,temp,1);
        return ans;
    }
};