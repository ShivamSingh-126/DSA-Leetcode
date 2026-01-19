class Solution {
public:
    string minWindow(string s, string t) 
    {
       int hs[256] = {0};
        int l=0,r=0,n=s.size(),m=t.size(),sidx=-1,count=0,minlen=INT_MAX;
        for(int i=0;i<m;i++)
        {
            hs[t[i]]++;
        }
        while(r < n)
        {
            if(hs[s[r]] > 0)
            {
                count++;
            }
            hs[s[r]]--;
            while(count == m)
            {
                if(r-l+1 < minlen)
                {
                    minlen=r-l+1;
                    sidx=l;
                }
                hs[s[l]]++;
                if(hs[s[l]] > 0)
                {
                    count--;
                }
                l++;          
            }
            r++;
        }
        return sidx==-1 ?"":s.substr(sidx,minlen);
    }
};