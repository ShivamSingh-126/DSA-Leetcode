class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        vector<int> last(10, -1);

        // store last occurrence of each digit
        for(int i = 0; i < s.size(); i++)
        {
            last[s[i] - '0'] = i;
        }
         // try to swap
        for(int i = 0; i < s.size(); i++)
        {
            for(int d = 9; d > s[i] - '0'; d--)
            {
                if(last[d] > i)
                {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};