class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) 
    {
        /*
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
        */
        vector<int>st(101,0);

        for(auto val : bulbs)
        {
            st[val] ^=1;
        }
        vector<int> ans;
        for(int i=0;i<101;i++)
        {
            if(st[i])
            ans.push_back(i);
        }
        return ans;
    }
};