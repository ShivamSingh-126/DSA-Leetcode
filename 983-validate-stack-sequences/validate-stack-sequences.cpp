class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        int j=0,i=0;
        while(i < n &&  j < n)
        {
            st.push(pushed[i]);

            while(!st.empty() && st.top()==popped[j] && j < n)
            {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};