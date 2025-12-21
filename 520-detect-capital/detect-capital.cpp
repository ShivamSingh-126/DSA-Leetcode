class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int n=word.size();
        int capitalletter=0;
        for( char c:word)
        {
            if(c >= 'A' && c <= 'Z') capitalletter++;
        }
        if(capitalletter==n) return true;
        if(capitalletter==0) return true;

        if(capitalletter == 1 && word[0] >= 'A' && word[0] <= 'Z')
        return true;

        return false;
    }
};