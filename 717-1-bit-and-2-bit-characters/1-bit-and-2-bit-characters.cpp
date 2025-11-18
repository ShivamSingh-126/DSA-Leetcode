class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int fb = 0, sb1 = 10, sb2 = 11;
        int ans = 0, count = 0;
        for (int i = 0; i < bits.size(); i++) {
            ans = ans * 10 + (bits[i] % 10);

            if (ans == fb || ans == sb1 || ans == sb2) {
                if (i == bits.size() - 1)
                    break;
                ans = 0;
            }
        }
        if (ans == fb)
            return true;

        return false;
    }
};