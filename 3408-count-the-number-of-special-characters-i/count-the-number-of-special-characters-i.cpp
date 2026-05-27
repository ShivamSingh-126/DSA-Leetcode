class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int n=word.size();
        vector<int>fstcap(26,-1);
        vector<int>lstsml(26,-1);

        for(int i=0;i<n;i++)
        {
            char ch=word[i];

            if(islower(ch))
            {
                lstsml[ch-'a']=i;
            }
            else
            {
                if(fstcap[ch-'A'] == -1)
                {
                    fstcap[ch-'A']=i;
                }
            }
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(lstsml[i] !=-1 && fstcap[i] != -1)
            {
                count++;
            }
        }
        return count;
    }
};