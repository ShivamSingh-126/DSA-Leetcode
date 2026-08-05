class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        /*

        // vector<int>l2r(n,1);
        // vector<int>r2l(n,1);
        vector<int>count(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                count[i] = max(count[i],count[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                count[i] = max(count[i],count[i+1]+1);
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res += count[i];
        }
        return res;
        */

        int candy = n;  // each have one candy

        int i=1;
        while(i < n)
        {
            if(ratings[i] == ratings[i-1])
            {
                i++;
                continue;
            }
            int peak=0;
            while(ratings[i] > ratings[i-1])    // inc slope
            {
                peak++;
                candy += peak;
                i++;
                if(i == n)
                {
                    return candy;
                }
            }
            int dip=0;
            while(i < n && ratings[i] < ratings[i-1])    // dec slope
            {
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peak,dip);
        }
        return candy;
    }
};