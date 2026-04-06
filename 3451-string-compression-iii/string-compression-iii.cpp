class Solution {
public:
    string compressedString(string word) 
    {
        string ans="";
        int n=word.length();
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(word[i] == word[i-1] && count <9)
            {
                count++;
            }
            else
            {
                ans+=to_string(count);
                ans+=word[i-1];
                count=1;
            }
        }
        ans+=to_string(count);
        ans+=word[n-1];
        return ans;
    }
};