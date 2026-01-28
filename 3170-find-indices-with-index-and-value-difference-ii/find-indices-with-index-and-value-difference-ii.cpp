class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) 
    {
        int n=nums.size();
        int minval=nums[0],maxval=nums[0];
        int minidx=0,maxidx=0;
       for(int i=indexDifference ;i<n;i++)
       {
            int j=i-indexDifference;

            if(nums[j]<minval)
            {
                minval=nums[j];
                minidx=j;
            }
            if(nums[j]>maxval)
            {
                maxval=nums[j];
                maxidx=j;
            }

            if(abs(nums[i] -minval)  >= valueDifference)
            {
                return {minidx,i};
            }
            if(abs(nums[i] -maxval)  >= valueDifference)
            {
                return {maxidx,i};
            }
       }
        return{-1,-1};
    }
};