class Solution {
public:
    static const int MOD = 1337;

    int power(int a,int b)
    {
        int res=1;
        a%=MOD;
        while(b > 0)
        {
            if(b & 1) res=(res * a) % MOD;
            a=(a*a) % MOD;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) 
    {
        if(a==1)  return 1;
        int ans = 1;
        a %= MOD;
        for(int i=0;i<b.size();i++)
        {
            ans=power(ans,10);
            ans=(ans * power(a,b[i])) % MOD;
        }

        return ans;
    }
};