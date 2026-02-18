class Solution {
public:
    int minimumDeletions(string s) 
    {
        int count=0;
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(!st.empty() && (st.top()=='b' && ch=='a'))
            {   st.pop();
                count++;
            }
            else
            {
                st.push(ch);
            }
        }
        return count;
    }
};