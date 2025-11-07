class Solution {
public:
bool ispossible(vector<int>& nums, int k,int maxsum)
{
    int Count = 1;
        long long Sum = 0; 

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxsum) return false;

            if (Sum + nums[i] <= maxsum)
            {
                Sum += nums[i];
            }
            else
            {
                Count++;
                Sum = nums[i];
            }
        }
        return Count <= k;
}
    int splitArray(vector<int>& nums, int k) 
    {
        long long sum=0,ans=-1,n=nums.size(),maxi=0;
        if(k>n) return -1;
         for(int x:nums)
        {
            sum+=x;
            maxi = max(maxi,(long long) x);
        }
        long long low=maxi,high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return (int)ans;
    }
};