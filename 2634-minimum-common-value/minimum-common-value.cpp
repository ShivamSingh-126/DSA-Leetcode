class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        // Brute force approach
        /*
        int n=nums1.size(),m=nums2.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans=min(ans,nums1[i]);
                }
            }
        }
        return ans==INT_MAX ?-1 : ans;
        */

        int i=0,j=0;
        int ans=INT_MAX;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                return nums1[i];
            }
            else if(nums1[i] < nums2[j])
            {
               i++;
            }
            else
            {
                j++;
            }
        }
        return -1;
    }
};