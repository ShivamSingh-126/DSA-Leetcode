class Solution {
public:
void countArrhelp(vector<int>&v,int &n,int &ans,int curnum)
{
    if(curnum ==n+1)
    {
        ++ans;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0 && (curnum % i ==0 || i % curnum ==0))
        {
            v[i]=curnum;
            countArrhelp(v,n,ans,curnum+1);
            v[i]=0;
        }
    }
}
    int countArrangement(int n) 
    {
        vector<int>v(n+1);
        int ans=0;
        countArrhelp(v,n,ans,1);
        return ans;
    }
};