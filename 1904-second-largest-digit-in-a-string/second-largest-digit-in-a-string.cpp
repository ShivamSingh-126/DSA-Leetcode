class Solution {
public:
    int secondHighest(string s) 
    {
        int gr = -1;
        int sgr = -1;

        for(char ch : s)
        {
            if(isdigit(ch))
            {
                if(ch -'0' > gr)
                {
                    sgr=gr;
                    gr = ch-'0';
                }
                else if(isdigit(ch) && ch -'0' < gr && ch -'0' > sgr)
                {
                    sgr = ch -'0';
                }
            }
            
        }
        return sgr;
    }
};