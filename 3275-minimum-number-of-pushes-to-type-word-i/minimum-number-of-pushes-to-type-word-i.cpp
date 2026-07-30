class Solution {
public:
    int minimumPushes(string word) 
    {
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
    }
};