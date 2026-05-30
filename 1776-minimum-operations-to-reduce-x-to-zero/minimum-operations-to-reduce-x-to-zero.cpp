class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int target = total - x;

        if(target < 0)  return -1;
        if(target == 0) return nums.size();

        int sum=0,left=0,maxlen=-1;

        for(int right =0;right<n;right++)
        {
            sum += nums[right];

            while(sum > target)
            {
                sum -=nums[left];
                left++;
            }
            if(sum == target)
            {
                maxlen=max(maxlen , right-left+1);
            }
        }
        return maxlen == -1 ? -1 : n-maxlen;
    }
};