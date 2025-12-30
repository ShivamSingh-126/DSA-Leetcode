class Solution {
public:
    char repeatedCharacter(string s) 
    {
        int n=s.size();
        vector<int>store(26,0);
        for(char ch :s)
        {
            store[ch - 'a']++;  //inc fre

            if(store[ch - 'a'] ==2) // check if fre ==2
            return ch;
        }
        return NULL;
    }
};