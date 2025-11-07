class Solution {
public:
void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int countpairs(vector<int>& arr, int low,int mid, int high)
    {
         int right=mid+1;
        int count=0;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && (long long)arr[i]>2LL*arr[right]) right++;
            count+=right-(mid+1);
        }
        return count;
    }
    // Recursive merge sort function
    int mergeSort(vector<int>& arr, int low, int high) {
        int count=0;
        if (low >= high)
            return count;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
       count+= mergeSort(arr, low, mid);

        // Recursively sort right half
       count+= mergeSort(arr, mid + 1, high);
       count+= countpairs(arr,low,mid,high);
        // Merge the two sorted halves
        merge(arr, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) 
    {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};