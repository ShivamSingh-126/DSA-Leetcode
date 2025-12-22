class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string hex = "0123456789abcdef";
        string ans = "";
        for (int i = 0; i < 8 && num != 0; i++) {
            ans = hex[num & 15] + ans;
            num >>= 4;
        }
        return ans;
    }
};