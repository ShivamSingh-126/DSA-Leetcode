class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        /*
        // Brute force   TC  O(n^2)
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {         
            int sum=0;   
            for(int j=i;j<n;j++)
            {
                sum=sum+nums[j];
                if(sum % k == 0) count++;
            }
        }
        return count;
        */
        unordered_map<int,int> freq; // it store remainder occurance
        freq[0]=1;
        int psum=0 , count=0;

        for(int i=0;i<nums.size();i++)
        {
            psum+=nums[i];
            int rem=psum % k;

            if(rem < 0)  rem+=k;    // check -ve remainder 
            count=count+freq[rem];  // prev rem occur how many time
            freq[rem]++;
        }
        return count;
    }
};