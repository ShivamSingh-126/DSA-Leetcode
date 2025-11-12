class Solution {
public:
    int romanToInt(string s) 
    {
       unordered_map<string, int> romanValue = {
            {"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},
            {"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},
            {"V",5},{"IV",4},{"I",1}
        };
            int ans = 0;

        for(int i=0;i<s.size();)
        {
            if(i + 1 < s.size() && romanValue.count(s.substr(i, 2)))
            {
                ans += romanValue[s.substr(i, 2)];
                i += 2;
            }
        else {
                ans += romanValue[s.substr(i, 1)];
                i++;
            }
        }
        return ans;
    }
};