class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ans = 0;
        for (int i = 0; i < bits.size(); i++) {
            ans = ans * 10 + (bits[i] % 10);
            if (ans == 0 || ans == 10 || ans == 11) {
                if (i == bits.size() - 1)
                    break;
                ans = 0;
            }
        }
        if (ans == 0)
            return true;
        return false;
    }
};