class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {/*
        // Brute Force
        int diff=0;
        vector<int>res;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                diff=abs(nums[i]-nums[j]);
                res.push_back(diff);
                diff=0;
            }
        }
        sort(res.begin(),res.end());

        return res[k-1];
        */
        //Using Max-Heap;
        /*
        priority_queue<int> maxHeap;

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);

                if (maxHeap.size() < k) {
                    maxHeap.push(diff);
                }
                else if (diff < maxHeap.top()) {
                    maxHeap.pop();
                    maxHeap.push(diff);
                }
            }
        }
        return maxHeap.top();
        */
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> vec(maxi+1,0);

        // count for each distance Diff how many pairs available
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=abs(nums[i]-nums[j]);
                vec[diff]++;
            }
        }
        for(int d=0;d<maxi+1;d++)
        {
            k-=vec[d];
            if(k<=0)
            {
                return d;
            }
        }
        return -1;
    }
};