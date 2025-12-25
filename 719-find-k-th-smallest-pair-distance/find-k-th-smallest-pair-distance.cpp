class Solution {
public:
int slidingwindowcount(vector<int>& nums, int d)
{
    int i=0;
    int j=1;
    int paircount=0;
    int n=nums.size();

    while(j<n)
    {
        while(nums[j] - nums[i] > d)
        {
            i++;
        }
        paircount+=(j-i);
        j++;
    }
    return paircount;
}
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

        /*
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
        */

        /*
        // Nth_element
        vector<int> dist;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dist.push_back(abs(nums[i] - nums[j]));
            }
        }

        // Place k-1 th smallest element at correct position
        nth_element(dist.begin(), dist.begin() + k - 1, dist.end());
        return dist[k - 1];
        */

        // Optimal Approach
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];

        int result=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int countpair=slidingwindowcount(nums,mid);

            if(countpair < k)
            {
                low=mid+1;
            }
            else
            {
                result=mid;
                high=mid-1;                
            }
        }
        return result;
    }
};