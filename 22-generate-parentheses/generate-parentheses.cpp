class Solution {
public:
    void generate(int n,int l,int r,string st,vector<string>&ans)
    {
        if(r==n)
        {
            ans.push_back(st);
            return;
        }
        if(l < n) generate(n,l+1,r,st+"(",ans);
        if(l > r) generate(n,l,r+1,st+")",ans);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        generate(n,0,0,"",ans);
        for(string s : ans)
        {
            cout << s << endl;
        }
        return ans;
    }
};