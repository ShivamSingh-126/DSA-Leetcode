class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
        }
        // if (sum % k == 0)
        //     return 0;
        // count = sum % k;    //remainder tell how min operation we have to do
        // to divisible by k return count;

        return sum % k;
    }
};