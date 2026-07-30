class Solution {
public:
    int minimumPushes(string word) 
    {
        /*
        int ans=0;
        unordered_map<int,int>mpp;  // 2 to 9
        int keys=2;

        for(char &ch : word)
        {
            if(keys >9)
            keys=2;

            mpp[keys]++;
            ans +=mpp[keys];

            keys++;
        }
        return ans;
        */
        int ans=0;
        vector<int>mpp(26,0);  

        for(char &ch : word)
        {
            mpp[ch-'a']++;
        }
        sort(mpp.begin(),mpp.end(),greater<int>());

        for(int i=0;i<26;i++)
        {
            int freq = mpp[i];

            int cost = i/8+1;

            ans +=cost * freq;
        }
        return ans;
    }
};