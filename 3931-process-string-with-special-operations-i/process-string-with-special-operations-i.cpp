class Solution {
public:
    string processStr(string s) 
    {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                str += s[i];
            }
            else if(s[i] == '*')
            {
                if (!str.empty())
                str.pop_back();
            }
            else if(s[i] == '#')
            {
                str += str;
            }
            else if(s[i] == '%')
            {
                reverse(str.begin(),str.end());
            }
        }
        return str;
    }
};