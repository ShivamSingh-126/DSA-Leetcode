class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {   
        if(s.length() != goal.length())  return false;

        // if equal
        if(s == goal)
        {
            vector<int> chk(26,0);
            for(char ch : s)
            {
                chk[ch - 'a']++;
                if(chk[ch - 'a'] > 1)  return true;
            }
        }
        // if not equal
        vector<int> diff;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != goal[i])
            {
                diff.push_back(i);
            }
        }
        if(diff.size() != 2)  return false;

        return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};