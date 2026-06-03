class Solution {
public:
    int characterReplacement(string s, int k) 
    {/*
        int maxlen=0,n=s.size();
        map<char,int> mpp;

        for(int i=0;i<n;i++)
        {
            mpp.clear();
            for(int j=i;j<n;j++)
            {
                mpp[s[j]]++;
                if(mpp.size()<=k)
                {
                    maxlen=max(maxlen,j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
        */
        /*
        int maxlen=0,l=0,r=0,maxFreq=0;
        map<char,int> mpp;
        while(r<s.size())
        {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);
            while((r-l+1)-maxFreq>k)
            {
                mpp[s[l]]--;                
                l=l+1;
            }          
            maxlen=max(maxlen,r-l+1);
            r=r+1;
        }
        return maxlen;
        */
        int n=s.size();
        int low=0;
        int maxfreq=INT_MIN;
        int maxlen=INT_MIN;
        unordered_map<char,int>mpp;

        for(int high=0;high<n;high++)
        {
            mpp[s[high]]++;

            maxfreq=max(maxfreq,mpp[s[high]]);

            while((high-low+1) - maxfreq > k)
            {
                mpp[s[low]]--;
                low++;
            }
            int len=high-low+1;
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};