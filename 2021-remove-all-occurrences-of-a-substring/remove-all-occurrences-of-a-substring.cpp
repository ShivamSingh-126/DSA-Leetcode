class Solution {
public:
    bool search(stack<char> st,string part,int m)
    {
        stack<char> chk=st;
        for(int i=m-1;i>=0;i--)
        {
            if(chk.top() != part[i])
            {
                return false;
            }
            chk.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) 
    {
        /*
        while(true)
        {
            int chk = s.find(part);
            
            if(chk == string :: npos) // if it not find in string 
            {
                break;
            }
            s.erase(chk,part.length());
        }
        return s;
        */

        //  Stack Approach
        stack<char> st;
        int n=s.length();
        int m=part.length();

        for(int i=0;i<n;i++)
        {
            st.push(s[i]);

            if(st.size() >=m && search(st,part,m) == true)
            {
                for(int j=0;j<m;j++)
                {
                    st.pop();
                }
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
    }
};