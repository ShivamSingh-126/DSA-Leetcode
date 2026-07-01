class Solution {
public:
    int firstUniqChar(string s) 
    {
        /*
        unordered_map<char,int>mpp;
        queue<int>Q;

        for(int i=0;i<s.size();i++)
        {
            if(mpp.find(s[i])==mpp.end())
            {
                Q.push(i);
            }
            mpp[s[i]]++;

            while(Q.size()>0 && mpp[s[Q.front()]]>1)
            Q.pop();
        }
        return Q.empty() ? -1:Q.front();
        */
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};