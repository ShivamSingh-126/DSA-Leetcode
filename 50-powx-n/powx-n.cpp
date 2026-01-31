class Solution {
public:
    double myPow(double x, int n) 
    {
        /*
        double ans;
        ans=pow(x,n);
        return ans;
        */
        long long a=n;
        double ans=1.0;
        if (a < 0) 
        {
            x = 1 / x;
            a = -a;
        }
        while(a > 0)
        {
            if(a%2==1)
            {
                ans=ans*x;  
                a--;            
            }
            else
            {
                x=x*x;
                a=a/2;
            }            
        }
        return ans;        
    }
};