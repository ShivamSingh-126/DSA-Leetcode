class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        /*
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
        */
        vector<int> hash(256,-1);
        int l=0,r=0,maxlen=0,n=s.length();
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l)
                {
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};