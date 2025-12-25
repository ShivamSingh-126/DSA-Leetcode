class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int bulls=0,cows=0;
        unordered_map<char,int> map1,map2;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])   
            bulls++;

            else                // Compare Character
            {
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }
        for(const auto& val:map1)      // Checking frequency
        {
            if(map2.find(val.first) != map2.end())
            {
                cows+=min(val.second , map2[val.first]);
            }
        }
        string res=to_string(bulls) + 'A' + to_string(cows) + 'B';     
        return res;
    }
};