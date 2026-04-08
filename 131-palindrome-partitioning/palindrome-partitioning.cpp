class Solution {
public:
    int n;
    bool isPalindrome(string &s,int idx,int i)
    {
        while(idx < i)
        {
            if(s[idx] != s[i])
            {
                return false;
            }
            idx++;
            i--;
        }
        return true;
    }
    void backtrack(string &s,int index,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(index == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(isPalindrome(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                backtrack(s,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        n=s.length();
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(s,0,ans,temp);
        return ans;
    }
};