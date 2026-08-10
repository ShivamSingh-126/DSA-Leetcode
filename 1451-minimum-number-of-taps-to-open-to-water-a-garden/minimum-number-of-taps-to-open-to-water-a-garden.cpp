class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int>startend(n+1,0);

        for(int i=0;i<=n;i++)
        {
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);

            startend[start] = max(startend[start],end); // find the maxtime
        }
        int taps=0;
        int maxend=0;
        int currend=0;

        for(int i=0;i<startend.size();i++)
        {
            if(i > maxend)  // if loop goes beyond maxend
            {
                return -1;
            }
            if(i > currend) // when to open tap
            {
                taps++;
                currend = maxend;
            }
            maxend = max(maxend,startend[i]);   // update maxend always
        }
        return taps;     
    }
};