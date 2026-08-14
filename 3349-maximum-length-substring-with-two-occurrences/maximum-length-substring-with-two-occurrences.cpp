class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        unordered_map<char,int>mpp;
        int n = s.size();
        int i=0,j=0;

        int max_len = 0;
        while(j < n)
        {
            mpp[s[j]]++;

            while(mpp[s[j]] > 2)
            {
                mpp[s[i]]--;
                i++;
            }
            max_len = max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};