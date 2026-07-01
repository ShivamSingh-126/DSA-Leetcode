class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
         unordered_map<char,int>mpp;
        
        for(auto ch : magazine)
        {
            mpp[ch]++;
        }
        for(auto ch : ransomNote)
        {
            if(mpp[ch] == 0)
            {
                return false;
            }
            mpp[ch]--;
        }
        return true;
    }
};