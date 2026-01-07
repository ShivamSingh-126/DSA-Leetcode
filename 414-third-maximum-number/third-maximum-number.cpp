class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        if(nums.size()<3)
        return *max_element(nums.begin(), nums.end());

       long x=LONG_MIN;
       long y=LONG_MIN;
       long z=LONG_MIN; 

       for(int i=0;i<nums.size();i++)
       {
        if(nums[i] == x || nums[i] == y || nums[i]==z) continue;
            if(nums[i]>x)
            {
                z=y;
                y=x;
                x=nums[i];
            }
            else if(nums[i] > y)
            {
                z=y;
                y=nums[i];
            }
            else if(nums[i]>z)
            {
                z=nums[i];
            }
       }
       if(z==LONG_MIN) return (int)x;

       return (int)z;
    }
};