class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        vector<string> bucket(s.size() + 1);
        for (auto& p : freq) {
            bucket[p.second].append(p.second, p.first);
        }
        string result;
        for (int i = s.size(); i > 0; i--) {
            result += bucket[i];
        }
        return result;
    }
};