class Solution {
public:
    bool hasSameDigits(string s) 
    {
        int i=0;
        while(s.size() != 2)
        {
            string str="";
            i=0;
            while(i != s.size()-1)
            {
                int digit = (s[i]- '0' + s[i+1] - '0') % 10;
                i++;
                str.push_back(digit + '0');
            }

            s=str;
        }
        return s[0] == s[1];
    }
};