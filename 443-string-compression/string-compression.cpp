class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0, count = 1;
        char pre = s[0];

        for (int i = 1; i < s.size(); i++) {
            if (pre == s[i]) {
                count++;
            } else {
                s[index++] = pre;
                if (count > 1) {
                    int start = index;
                    while (count) {
                        s[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                pre = s[i];
                count = 1;
            }
        }
        s[index++] = pre;
        if (count > 1) {
            int start = index;
            while (count) {
                s[index++] = (count % 10) + '0';
                count/= 10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }
        return index;
    }
};