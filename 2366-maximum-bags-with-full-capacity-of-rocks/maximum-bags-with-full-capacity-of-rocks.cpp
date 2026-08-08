class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n=rocks.size();
        vector<int>reqrock;

        for(int i=0;i<n;i++)
        {
            reqrock.push_back(capacity[i]-rocks[i]);    // find the rem rock to fill bag
        }
        sort(reqrock.begin(),reqrock.end());    // min num gives first

        int maxbag=0;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(additionalRocks >= reqrock[i])
            {
                additionalRocks -= reqrock[i];
                maxbag++;
            }
            else
            {
                break;
            }
        }
        return maxbag;
    }
};