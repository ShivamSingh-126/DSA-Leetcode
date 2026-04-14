class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int n=s.length();
        string str;
        vector<bool>taken(26,false);
        vector<int>lstidx(26);

        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            lstidx[ch-'a']=i;
        }
        for(int i=0;i<n;i++)
        {
            char ch=s[i];

            int idx=ch-'a';

            if(taken[idx] == true) continue;

            while(str.length() > 0 && str.back() > ch && lstidx[str.back() - 'a'] > i)
            {
                taken[str.back() - 'a'] = false;
                str.pop_back();
            }
            str.push_back(ch);
            taken[idx]=true;
        }
        return str;
    }
};