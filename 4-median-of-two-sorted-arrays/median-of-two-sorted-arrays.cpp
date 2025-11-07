class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i,j,m=nums1.size(),n=nums2.size(),k=0;
        vector<int>nums3;
        for(i=0;i<m;i++)
        {
            nums3.push_back(nums1[i]);
        }
        for(i=0;i<n;i++)
        {
             nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(),nums3.end());
        int x=nums3.size();
        if(x%2==0)
        {
           return (static_cast<double>(nums3[x/2]+nums3[x/2-1]))/2.0;
        }
        else
        {
            return static_cast<double>(nums3[x/2.0]);
        }
       
    }
};