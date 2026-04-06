class Solution {
public:
    long long minimumSteps(string s) 
    {
        /*
        int n=s.length();
        int count=0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i] == '1' && s[j] == '0') count++;
            }
        }
        return count;
        */
        long long count=0;
        long long zeros=0;
        for(char ch : s)
        {
            if(ch == '1')
            {
                count++;
            }
            else
            {
                zeros+=count;
            }
        }
        return zeros;
    }
};