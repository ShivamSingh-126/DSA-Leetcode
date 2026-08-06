class Solution {
public:
    int smallestNumber(int n, int t) 
    {

       while(true)
       {
            int num=1,val = n;

            while(val > 0)
            {
                num *= val %10;
                val = val /10;
            }

            if(num % t == 0)  return n;

            n++;
       }
    }
};