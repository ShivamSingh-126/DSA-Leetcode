class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        // int temp;
        // if(n<0)return false;
        // for(int i=0;i<31;i++)
        // {
        //     temp=pow(2,i);
        //     if(temp==n)return true;
        // }
        // return false;
         if (n <= 0) return false;
        return (n & (n-1))==0;
    }
};