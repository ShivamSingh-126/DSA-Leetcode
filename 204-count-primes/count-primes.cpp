class Solution {
public:
    int countPrimes(int n) 
    {
        /*
        if(n<=2) return 0;

        int total=0;
        for(int i=3;i < n;i++)        
        {   
            int count=0;
            for(int j=1;j*j<=i;j++) // also j but it gives TLE
            {
                if(i%j==0)
                {
                    count++;
                }
            }
            if(count==2) total++;
        }
        return total;
        */
        if(n<=2) return 0;
        vector<bool> isprime(n,true);
        isprime[0] = isprime[1] = false;
        for(int i=2; i*i < n; i++)
        {
            if(!isprime[i])  continue;

            for(int j=i*i; j<n; j+=i)
            {
                isprime[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(isprime[i]) count++;
        }

        return count;
    }
};