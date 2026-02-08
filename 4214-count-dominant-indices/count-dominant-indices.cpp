class Solution {
public:
    int dominantIndices(vector<int>& nums) 
    {
        /*
        int n=nums.size(),sum=0,dom=0,i,j,count=0;
        for( i=0;i<n-1;i++)
        {
            int check=nums[i];
            sum=0;
            count=0;
            for( j=i+1;j<n;j++)
            {
                sum+=nums[j];
                count++;
            }
            if(check > sum/count)  dom++;
        }
        return dom;
        */
        int n=nums.size();
        long long sum=0;
        for(int val : nums)
        {
            sum+=val;
        }
        int dom=0,count=0;
        for(int i=0;i<n-1;i++)
        {
            sum-=nums[i];
            count=n-i-1;
            double avg=(double)sum/count;

            if(nums[i] > avg) dom++;
        }
        return dom;
    }
};