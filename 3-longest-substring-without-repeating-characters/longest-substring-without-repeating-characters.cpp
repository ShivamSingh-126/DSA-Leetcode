class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char>st;
        int maxi=0;
        int l=0,r=0;

        while(r<s.length())
        {
            if(st.find(s[r])==st.end())
            {
                st.insert(s[r]);
                maxi=max(maxi,(int)st.size());
                r++;
            }
            else
            {
                st.erase(s[l]);
                l++;
            }
        }
        return maxi;
    }
};