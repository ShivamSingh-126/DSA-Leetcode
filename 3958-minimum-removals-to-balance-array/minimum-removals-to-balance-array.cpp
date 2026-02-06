class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {  // Brute force 
    /*
        int n=nums.size();
        if(n==1)  return 0;
        sort(nums.begin(),nums.end());
        int retmin=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int j=n-1;        
            int mini=nums[i];
            while(j>=i)
            {
                int maxi=nums[j];
                if((long long)maxi <= (long long)mini*k)
                {
                    int re=n-(j-i+1);
                    retmin=min(re,retmin);
                    break;
                }
                j--;
            }
        }
        return retmin;
        */

        int n=nums.size();
        if(n<=1)  return 0;
        sort(nums.begin(),nums.end());
        int numkeep=1;
        int j=0;
        for(int i=0;i<n;i++)
        {           
            while(j<n && (long long)nums[j] <= (long long)nums[i]*k)
            {
                j++;
            }
            numkeep=max(numkeep,j-i);
        }
        return n-numkeep;
    }
};