class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for(int &val :asteroids)
        {
            while(!st.empty() && val < 0 && st.top() >0)
            {
                int sum=val+st.top();

                if(sum < 0)
                {
                    st.pop();
                }
                else if(sum > 0)
                {
                    val =0;
                }
                else
                {
                    st.pop();
                    val=0;
                }
            } 
            if(val != 0)           
            {
                st.push(val);
            }
        }
        int n=st.size();
        vector<int> ans(n);
        int i=n-1;
        while(!st.empty())
        {
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};