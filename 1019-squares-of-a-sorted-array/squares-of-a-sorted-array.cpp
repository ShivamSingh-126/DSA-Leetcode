class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n);
        int start=0,end=n-1;
        int store=n-1;  
        // because we fill vec from last acc to greatest
        while(store >= 0)
        {
            int a=nums[start] * nums[start];
            int b=nums[end] * nums[end];

            if(a>b)
            {
                ans[store]=a;
                start++;
            }
            else
            {
                ans[store]=b;
                end--;
            }
            store--;
        }
        return ans;
    }
};