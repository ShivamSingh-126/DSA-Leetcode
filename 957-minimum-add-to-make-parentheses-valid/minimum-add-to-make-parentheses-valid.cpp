class Solution {
public:
    int minAddToMakeValid(string s) {
        /*
        if(s.empty()) return 0;

        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
                cnt1++;
            else
                cnt2++;
        }
        return abs(cnt1-cnt2);
        */

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};