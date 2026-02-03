class Solution {
public:
    int kthFactor(int n, int k) 
    {
        int count=0;
        for(int i=n;i>=1;i--)
        {
            if(n % i==0)
            {
                count++;
                if(count==k) return n / i;
            }
        }
        return -1;
    }
};