class Solution {
public:
    int mirrorDistance(int n) 
    {
        int newnum=0;
        int x=n;
        while(n > 0)
        {
            newnum=newnum*10+n%10;
            n=n/10;
        }
        return abs(x-newnum);
    }
};