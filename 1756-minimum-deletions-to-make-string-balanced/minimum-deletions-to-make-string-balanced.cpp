class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n=s.size();
        /*
        int count=0;
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
        */

        int counta=0;
        if (n == 0) return 0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                counta++;
            }
        }
        int count=INT_MAX;
        int countb=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')  counta--;
            
            count=min(count,counta+countb);

            if(s[i]=='b') countb++;
        }

        return count;
    }
};