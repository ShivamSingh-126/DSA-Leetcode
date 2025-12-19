class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int len=s.length();
        int count=0;
        string ans="";
        for(int i=0;i<len;i++)
        {
            if(s[i]==')') count--;
            if(count!=0) ans+=s[i];
            if(s[i]=='(') count++;
        }
        return ans;
    }
};