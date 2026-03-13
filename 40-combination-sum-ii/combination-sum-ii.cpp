class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans,vector<int> &temp,int index)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(candidates[i] > target)  break;
            if(i > index && candidates[i] == candidates[i-1])  continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        unordered_set<int> st;
        sort(candidates.begin(),candidates.end());        
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,target,ans,temp,0);
        return ans;
    }
};