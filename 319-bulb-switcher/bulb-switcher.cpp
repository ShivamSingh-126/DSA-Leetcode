class Solution {
public:
    int bulbSwitch(int n) 
    {
        // Brute force
        /*
        if(n <=1) return n;

        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int ch=1;ch<=n;ch++)
            {
                if(ch % (i+1) ==0)
                {
                    if(ans[ch-1] == 0)  ans[ch-1]=1;
                    else ans[ch-1]=0;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i] ==1) count++;
        }
        return count;
        */
        return sqrt(n);
    }
};