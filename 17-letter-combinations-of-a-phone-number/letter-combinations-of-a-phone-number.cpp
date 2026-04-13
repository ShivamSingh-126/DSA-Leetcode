class Solution {
public:
    vector<string>ans;
    void solve(int idx,string &digits,unordered_map<int, string>& telephone,string &temp)
    {
        if(idx >= digits.length())
        {
            ans.push_back(temp);
            return;
        }
        char ch=digits[idx]-'0';
        string str=telephone[ch];

        for(int i=0;i<str.length();i++)
        {
            temp.push_back(str[i]);
            solve(idx+1,digits,telephone,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int n= digits.length();
        if(n == 0)  return {};
        unordered_map<int, string> telephone;
        telephone[2] = "abc";
        telephone[3] = "def";
        telephone[4] = "ghi";
        telephone[5] = "jkl";
        telephone[6] = "mno";
        telephone[7] = "pqrs";
        telephone[8] = "tuv";
        telephone[9] = "wxyz";

        string temp="";
        solve(0,digits,telephone,temp);

        return ans;
    }
};