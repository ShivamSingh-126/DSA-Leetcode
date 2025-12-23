class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // Sorting
        /*
        sort(nums.begin(),nums.end());

        for(int chk=1;chk<nums.size();chk++)
        {
            if(nums[chk]==nums[chk-1])  return nums[chk];
        }
        return -1;
        */
        // Hashset
        /*
        unordered_set<int> st;

        for (int x : nums) {
            if (st.count(x))
                return x;    
            st.insert(x);
        }
        return -1;
        */
        //  Optimal  Loop detection

        int slow=0;
        int fast=0;
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow != fast);
        slow=0;
        while(slow != fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;

    }
};