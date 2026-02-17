class Solution {
public:
    long long sumSubarrayMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL(n), NSR(n);
        stack<int> st;

        // NSL (Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // NSR (Next Smaller or Equal Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGL(n), NGR(n);
        stack<int> st;

        // NGL (Previous Greater Element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            NGL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // NGR (Next Greater or Equal Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            NGR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NGL[i];
            long long right = NGR[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};