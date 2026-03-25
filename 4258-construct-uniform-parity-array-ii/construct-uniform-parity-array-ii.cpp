class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        int n=nums1.size();
        int even=0;
        int minodd=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums1[i] % 2 != 0)
            {
               minodd=min(minodd,nums1[i]);
            }
            else
            {
                even++;
            }
        }
        if(even == n)  return true;
        for(int i=0;i<n;i++)
        {
            if(nums1[i] % 2 == 0 && (nums1[i] < minodd)) return false;
        }

        return true;
        
    }
};