class Solution {
public:
    string maximumXor(string s, string t) 
    {
        int ons = 0, zr = 0;
        for(char ch : t)
        {
            if(ch == '1') ons++;
            else zr++;
        }

        string ans = "";

        for(char ch : s)
        {
            if(ch == '0')
            {
                if(ons > 0)
                {
                    ans.push_back('1'); 
                    ons--;
                }
                else
                {
                    ans.push_back('0'); 
                    zr--;
                }
            }
            else
            {
                if(zr > 0)
                {
                    ans.push_back('1');
                    zr--;
                }
                else
                {
                    ans.push_back('0'); 
                    ons--;
                }
            }
        }
        return ans;
    }
};