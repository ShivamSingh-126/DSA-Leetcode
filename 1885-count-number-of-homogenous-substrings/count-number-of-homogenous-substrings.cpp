class Solution {
public:
    int countHomogenous(string s) 
    {
        int n=s.length();
        int mod=1e9+7;
        long long count=0;

        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j<n && s[j] == s[i])
            {
                j++;
            }
            long long len=j-i;

            count += (len*(len+1))/2;
            i=j-1;
        }
        return count % mod;
    }
};