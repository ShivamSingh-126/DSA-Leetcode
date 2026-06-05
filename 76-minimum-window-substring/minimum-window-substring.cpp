class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>mpp;
        for(char ch : t)
        {
            mpp[ch]++;
        }
        int low=0,n=s.size(),minlen=INT_MAX;
        int req=t.size(),start=0;
        for(int high=0;high<n;high++)
        {
            if(mpp[s[high]] >0)
            {
                req--;
            }
            mpp[s[high]]--;

            while(req == 0)
            {
                if(high-low+1 < minlen)
                {
                    minlen=high-low+1;
                    start=low;
                }
                mpp[s[low]]++;

                if(mpp[s[low]] > 0)
                {
                    req++;
                }
                low++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(start,minlen);
    }
};