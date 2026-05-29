class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        int res=INT_MAX;
        for(int x : nums)
        {
            int val=x;
            int sum=0;
            while(val > 0)
            {
                sum += val %10 ;
                val /= 10;
            }
            res=min(res,sum);
        }
        return res;
    }
};