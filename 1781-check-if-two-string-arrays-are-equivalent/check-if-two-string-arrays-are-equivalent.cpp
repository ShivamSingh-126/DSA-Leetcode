class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1="";
        string s2="";

        for(auto ch1 : word1) s1+=ch1;
        for(auto ch2 : word2) s2+=ch2;

        return s1 == s2;
    }
};