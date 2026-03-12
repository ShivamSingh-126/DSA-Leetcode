class Solution {
public:
    int findComplement(int num) {
        if(num==0)   return 1;
        string newnum="";
        while(num != 0)
        {
           newnum+=(num%2)+'0';
            num=num/2;
        }
        reverse(newnum.begin(), newnum.end());
        for(char &c : newnum)
        {
            c = (c == '0') ? '1' : '0';
        }
        int n=0;
        for(int i=0;i<newnum.size();i++)
        {
            n=n*2 + (newnum[i]-'0');
        }
        return n;
    }
};