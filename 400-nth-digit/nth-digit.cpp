class Solution {
public:
    int findNthDigit(int n) {
        long long digitlen = 1;
        long long count = 9;
        long long start = 1;
        // find the digit group
        while (n > digitlen * count) {
            n -= digitlen * count;
            digitlen++;
            count *= 10;
            start *= 10;
        }
        start += (n - 1) / digitlen; // find real number
        // change into string to find its index number
        string num = to_string(start);
        return num[(n - 1) % digitlen] - '0';
    }
};