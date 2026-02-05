class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> pcount(26,0);
        vector<int> scount(26,0);

        vector<int> result;
        if (s.size() < p.size()) return result;

        for(char c:p)
        {
            pcount[c-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            scount[s[i]-'a']++;

            if(i>= p.size())
            {
                scount[s[i-p.size()]-'a']--;
            }
            if(scount == pcount)
            {
                result.push_back(i-p.size()+1);
            }
        }
        return result;
    }
};