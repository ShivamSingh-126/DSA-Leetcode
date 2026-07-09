class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int low=0,high=n-1;
        while(low <= high)
        {
            int guess=low+(high-low)/2;
            if(nums[guess]==target)  return guess;

            if(nums[guess] > nums[high] )
            {
                if(nums[guess] < target)
                {
                    low=guess+1;
                }
                else
                {
                    if(nums[low] > target)
                    low=guess+1;
                    else
                    high=guess-1;
                }
            }
            else
            {
                if(nums[guess] > target)
                {
                    high=guess-1;
                }
                else
                {
                    if(nums[high] < target)
                    high=guess-1;
                    else
                    low=guess+1;
                }
            }
        }
        return -1;
    }
};