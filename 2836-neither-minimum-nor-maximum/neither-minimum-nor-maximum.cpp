class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        if(nums.size()<=2) return -1;
        // int maxi=INT_MIN;
        // int mini=INT_MAX;

        // for(int val:nums)
        // {
        //     maxi=max(val,maxi);
        //     mini=min(val,mini);
        // }
        // for(int x:nums)
        // {
        //     if(x != maxi && x != mini)
        //     {
        //         return x;
        //     }
        // }
        // return -1;
        int a=nums[0],b=nums[1],c=nums[2];
        return a+b+c-max({a,b,c})-min({a,b,c});
    }
};