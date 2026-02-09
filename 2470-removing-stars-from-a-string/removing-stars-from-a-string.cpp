class Solution {
public:
    string removeStars(string s) 
    {
        /*
        stack<char> st;
        int n=s.size();

        for(int i=0;i<n ;i++)
        {
            if(s[i] != '*')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        */
        int n=s.size();
        int forw=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] != '*')
            {
                s[forw++]=s[i];
            }
            else
            {
                forw--;
            }
        }
        // return substring from 0 to forward index 
        return s.substr(0,forw);
    }
};