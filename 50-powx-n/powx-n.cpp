class Solution {
public:
    double solve(double x, long long n)
    {
        if( n== 0) return 1;
        double val=solve(x,n/2);
        if(n%2==0)  return val*val;

        return  x*val*val;
    }
    double myPow(double x, int n) 
    {
        /*
        double ans;
        ans=pow(x,n);
        return ans;
        */
        /*
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
        */   
        long long N=n;

        if(N < 0)
        {
            x=1/x;
            N=-N;
        }  
        return solve(x,N);
    }
};