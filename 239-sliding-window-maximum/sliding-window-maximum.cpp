class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n=nums.size();
        /*
        if(n==1)  return nums;
        vector<int> ans;
        for(int i=0;i<=n-k;i++)
        {
            int maxi=nums[i];
            for(int j=i;j<i+k;j++)
            {
                maxi=max(nums[j],maxi);
            }
            ans.push_back(maxi);
        }
        return ans;
        */
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++)
        {
            while(dq.size() > 0 && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++)
        {
            ans.push_back(nums[dq.front()]);

            while(dq.size() > 0 && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(dq.size() > 0 && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};