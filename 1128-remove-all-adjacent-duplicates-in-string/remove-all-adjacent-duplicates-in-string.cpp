class Solution {
public:
    string removeDuplicates(string s) 
    {
        /*
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        // push into string
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse 
        reverse(ans.begin(),ans.end());
        return ans;
        */

        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty() || ans.back() != s[i])
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};