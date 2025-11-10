class Solution {
public:
    string reverseWords(string s) 
    {
       int n=s.size();
       string ans="";
       reverse(s.begin(),s.end());      // reverse full string 

       for(int i=0;i<n;i++)
       {
            string word="";
            while(i<n && s[i]!=' ')     // execute one word
            {
                word+=s[i];
                i++;
            }
       reverse(word.begin(),word.end());    //Again reverse word
       if(word.length() > 0)
       {
            ans+=" "+word;      //// concatenate with space if needed
       }
       }
       return ans.substr(1);
    }
};