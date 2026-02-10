class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*   Brute Force Approach

        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {

            int count=0;
            for(int j=i+1;j<n;j++)
            {
                if(temperatures[i] < temperatures[j])
                {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
        */
        // Monotonic stack
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};