class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) 
    {
        // sort(bulbs.begin(),bulbs.end());
        unordered_set<int>st;

        for(auto val : bulbs)
        {
            if(st.count(val))
            st.erase(val);

            else
            st.insert(val);
        }
        vector<int> ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};