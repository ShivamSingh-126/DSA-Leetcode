class Solution {
public:
    int calculate(string s) 
    {
        int n=s.length();
        stack<int>st;
        int num=0;
        char op='+';

        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if (isdigit(ch)) 
            {
                num = num * 10 + (ch - '0');
            }
            if(!isdigit(ch) && ch !=' ' || i==s.length()-1)
            {
                if(op=='+') st.push(num);
                else if(op=='-') st.push(-1*num);
                else if(op=='*')
                {
                    int top=st.top();
                    st.pop();
                    st.push(num*top);
                }
                else if(op=='/')
                {
                    int top=st.top();
                    st.pop();
                    st.push(top/num);
                }
                op=ch;
                num=0;
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};