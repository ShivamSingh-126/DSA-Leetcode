class Solution {
public:
    int romanToInt(string s) 
    {
    //    unordered_map<string, int> romanValue = {
    //         {"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},
    //         {"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},
    //         {"V",5},{"IV",4},{"I",1}
    //     };
    //         int ans = 0;

    //     for(int i=0;i<s.size();)
    //     {
    //         if(i + 1 < s.size() && romanValue.count(s.substr(i, 2)))
    //         {
    //             ans += romanValue[s.substr(i, 2)];
    //             i += 2;
    //         }
    //     else {
    //             ans += romanValue[s.substr(i, 1)];
    //             i++;
    //         }
    //     }
    //     return ans;

      unordered_map<char, int> roman = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                ans -= roman[s[i]];
            } else {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};