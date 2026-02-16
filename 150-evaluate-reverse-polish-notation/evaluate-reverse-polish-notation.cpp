class Solution {
public:
    int solve(int b,int a,string s)
    {
        if(s == "+")
        {
            return a+b;
        }
        else if(s=="-")
        {
            return b-a;
        }
        else if(s=="*")
        {
            return a*b;
        }
        return b/a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& val : tokens) {
            if (val == "+" || val == "-" || val == "*" || val == "/") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int ans = solve(b, a, val);

                st.push(ans);
            } else {
                st.push(stoi(val));
            }
        }
        return st.top();
    }
};