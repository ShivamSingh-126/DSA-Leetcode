class Solution {
public:
    vector<int> find(int n) {
        for (int i = sqrt(n); i >= 1; i--) {
            if (n % i == 0) {
                return {i, n / i};
            }
        }
        return {};
    }
    vector<int> closestDivisors(int num) {
        vector<int> x = find(num + 1);
        vector<int> y = find(num + 2);

        if (abs(x[0] - x[1]) < abs(y[0] - y[1]))
            return x;
        return y;
    }
};