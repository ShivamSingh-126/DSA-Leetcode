class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> st;

        for (char ch : expression)
        {
            if (ch == ',') continue;

            if (ch != ')') 
            {
                st.push(ch);
            }
            else 
            {
                bool hasTrue = false;
                bool hasFalse = false;

                while (st.top() != '(')
                {
                    char let = st.top();
                    st.pop();

                    if (let == 't') hasTrue = true;
                    if (let == 'f') hasFalse = true;
                }

                st.pop(); 
                char op = st.top();
                st.pop(); 

                if (op == '!')
                {
                    st.push(hasTrue ? 'f' : 't');
                }
                else if (op == '&')
                {
                    st.push(hasFalse ? 'f' : 't');  
                }
                else if (op == '|')
                {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};