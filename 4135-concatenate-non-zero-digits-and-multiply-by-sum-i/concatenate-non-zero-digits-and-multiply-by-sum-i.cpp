class Solution {
public:
    long long sumAndMultiply(int n) 
    {
        string st=to_string(n);

        long long sum=0;
        long long num=0;

        for(char ch:st)
        {
            if(ch != '0')
            {
                int digit = ch-'0';
                num = num*10+digit;
                sum+=digit;
            }
        }
        return num*sum;
    }
};