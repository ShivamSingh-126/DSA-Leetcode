class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size();
        int rng=0;
        for(int i=n-1;i>=0;i--)
        {
            if(colors[i] != colors[0])
            {
                rng=max(rng,i);
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(colors[i] != colors[n-1])
            {
                rng=max(rng,n-i-1);
                break;
            }
        }
        return rng;
    }
};