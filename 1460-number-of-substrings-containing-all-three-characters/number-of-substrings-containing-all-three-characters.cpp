class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n=s.size(),count=0;
        int lstseen[3]={-1,-1,-1};
        for(int i=0;i<n;i++)
        {
            lstseen[s[i]-'a']=i;
            if(lstseen[0] !=-1 && lstseen[1] !=-1 && lstseen[2] !=-1)
            {
                count+=1+min({lstseen[0],lstseen[1],lstseen[2]});
            }
        }
        return count;
    }
};