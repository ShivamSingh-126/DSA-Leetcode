class Solution {
public:
    int countMonobit(int n) 
    {
        if(n==0) return 1;
        if(n==1) return 2;
        int count = 1;
        int num=1;
        while(num <= n)
        {
            count++;
            num = (num << 1) | 1;
        }
        return count;
    }
};