class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        /*
        int n=nums.size(); 
        if(n<3)  return 0;
        int count=0;      
        for(int i=0;i<n-2;i++)
        {
            int j=i+2;
            int diff=nums[i+1]-nums[i];
            while(j<n)
            {
                if((nums[j]-nums[j-1])==diff) 
                {
                    count++;
                }
                j++;
            }
        }
        return count;
        */
        int n=nums.size(); 
        if(n<3)  return 0;
        int total=0;
        int curr=0;  

        for(int i=2;i<n;i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2])
            {
                curr++;
                total+=curr;
            }
            else
            {
                curr=0;
            }
        }
        return total;
    }
};