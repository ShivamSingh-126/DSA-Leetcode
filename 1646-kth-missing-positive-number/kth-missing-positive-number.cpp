class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*  Brute force

        int mini = 1;
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> temp;
        for (int i = mini; temp.size() < k; i++) {
            bool flag = false;
            for (int j : arr) {
                if (j == i) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                temp.push_back(i);
        }
        return temp[k - 1];
        */

        //   Optimal solution 
        int n=arr.size();
        int low=0,high=n-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high+1+k;
        // return low+k;

    }
};