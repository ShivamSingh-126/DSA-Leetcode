class Solution {
public:
    int beautySum(string s) 
    {
        int len=s.length();
        int countbeauty=0;
        for(int i=0;i<len;i++)
        {
            vector<int> fre(26,0);
            for(int j=i;j<len;j++)
            {
                fre[s[j]-'a']++;

                int maxfreq = 0;
                int minfreq = INT_MAX;

                for(int k=0;k<26;k++)
                {
                    if(fre[k]>0)
                    {
                        maxfreq=max(maxfreq,fre[k]);
                        minfreq=min(minfreq,fre[k]);
                    }
                }
                countbeauty+=(maxfreq - minfreq);
            }
        }
        return countbeauty;
    }
};