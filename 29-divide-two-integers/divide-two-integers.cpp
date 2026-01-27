class Solution {
public:
    int divide(int dividend, int divisor) 
    {
       if(dividend == divisor)  return 1;
       if(dividend == INT_MIN && divisor == -1) return INT_MAX;

       bool sign = (dividend >= 0) == (divisor >= 0);
       long n=labs(dividend);
       long d=labs(divisor);
       long quotient=0;
       while(n >= d)
       {
            long temp=d;
            int count=0;
            while(n >= (temp << 1))
            {
                temp <<= 1;
                count++;                
            }
            quotient +=1l << count;
            n-=temp;
       }
       return sign ? quotient: -quotient;
    }
};