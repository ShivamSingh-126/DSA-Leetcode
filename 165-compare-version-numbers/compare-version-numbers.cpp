class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> x;
        string temp;
        stringstream ss1(version1);
        while (getline(ss1, temp, '.')) {
            x.push_back(stoi(temp));
        }

        vector<int> y;
        stringstream ss2(version2);
        while (getline(ss2, temp, '.')) {
            y.push_back(stoi(temp));
        }

        int n = x.size(), m = y.size();
        int len=max(n,m);
        for(int i=0;i<len;i++)
        {
            int a = i < n ? x[i] : 0; 
            int b = i < m ? y[i] : 0;

            if(a < b) return -1;

            if(a > b) return 1;
        }

        return 0;
    }
};