class Solution {
public:
    bool ifcorrect(string& s, int len) {
        int n = s.size();
        int fstfre[256] = {0};

        for (int i = 0; i < len; i++) {
            fstfre[(unsigned char)s[i] - 'a']++;
        }
        for (int j = len; j < n; j += len) {
            int rngfre[256] = {0};
            for (int k = j; k < j + len; k++) {
                rngfre[(unsigned char)s[k] - 'a']++;
            }
            for (int a = 0; a < 256; a++) {
                if (fstfre[a] != rngfre[a])
                    return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        /*
        //   Wrong Approach
        unordered_set<char> fre;
        for(int i=0;i<s.size();i++)
        {
            if(fre.count(s[i]) > 0)  continue;
            else
            {
                fre.insert(s[i]);
            }
        }
        return fre.size();
        */
        int sz = s.size();

        for (int len = 1; len <= sz; len++) {
            if (sz % len == 0 && ifcorrect(s, len))
                return len;
        }
        return sz;
    }
};