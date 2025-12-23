class Solution {
public:
    vector<int> count;

    void mergeSort(vector<pair<int, int>>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<pair<int, int>>& arr, int low, int mid, int high) {
        vector<pair<int, int>> temp;
        int left = low, right = mid + 1;
        int rightCount = 0;

        while (left <= mid && right <= high) {
            if (arr[right].first < arr[left].first) {
                rightCount++;
                temp.push_back(arr[right]);
                right++;
            } else {
                count[arr[left].second] += rightCount;
                temp.push_back(arr[left]);
                left++;
            }
        }

        while (left <= mid) {
            count[arr[left].second] += rightCount;
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        // Brute force
        /*
        vector<int>res;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>nums[j])
                {
                   count++;
                }
            }
            res.push_back(count);
        }
        return res;
        */
        int n = nums.size();
        count.assign(n, 0);

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);
        return count;
    }
};