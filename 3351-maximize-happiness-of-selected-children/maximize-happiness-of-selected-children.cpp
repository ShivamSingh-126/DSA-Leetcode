class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        /*
        int n = happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());

        long long maxhappy=0;
        for(int i=0;i<n-1;i++)
        {
            if(k > 0)
            {
                maxhappy += happiness[i];
                k--;
            }
            for(int j=i+1;j<n;j++)
            {
                if(happiness[j] > 0)
                {
                    happiness[j]--;
                }
            }
        }
        return maxhappy;
        */

        int n = happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());

        long long maxhappy=0;
        for(int i=0;i<k;i++)
        {
            if(happiness[i] - i <= 0) break;

            maxhappy += happiness[i]-i;
        }
        return maxhappy;
    }
};