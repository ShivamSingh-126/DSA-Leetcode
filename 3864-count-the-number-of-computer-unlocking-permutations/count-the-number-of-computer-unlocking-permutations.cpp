class Solution {
public:
    int countPermutations(vector<int>& complexity) 
    {
        int n=complexity.size();
        long long total=1;
        int mod=1e9+7;
        for(int i=1;i<n;i++)
        {
            if(complexity[0] >= complexity[i])  return 0;

            // each comp has (n-1) possibility so (n-1)!
            total=(total * i) % mod;
        }
        return total;
    }
};