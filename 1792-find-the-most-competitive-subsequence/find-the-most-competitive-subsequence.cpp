class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        vector<int>st;
        int n=nums.size();
        int remove=n-k;
        for(auto val : nums)
        {
            while(!st.empty() && st.back() > val && remove > 0 )
            {
                st.pop_back();
                remove--;
            }
            st.push_back(val);
        }
        st.resize(k);
        return st;
    }
};