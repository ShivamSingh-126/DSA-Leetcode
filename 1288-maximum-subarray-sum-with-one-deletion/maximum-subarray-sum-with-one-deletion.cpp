class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        //  Revise Again Seriously
        int n=arr.size();
        if(n==1)  return arr[0];
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int res=INT_MIN;

        for(int i=1;i<n;i++)
        {
            int prenodelete = nodelete;
            int preonedelete = onedelete;

            nodelete = max(nodelete+arr[i],arr[i]);

            int v2;
            if(preonedelete == INT_MIN)
            v2=arr[i];
            else
            v2=preonedelete+arr[i];

            onedelete = max(v2,prenodelete);

            res=max(res,max(onedelete,nodelete));
        }
        return res;
    }
};