class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int n=s.size();
        for(int i=0;i<n;i+=2*k)
        {
            int a=i;
            int b=min(i+k-1,n-1);
            while(a<b)
            {
                swap(s[a],s[b]);
                a++;
                b--;
            }
        }
        return s;
    }
};