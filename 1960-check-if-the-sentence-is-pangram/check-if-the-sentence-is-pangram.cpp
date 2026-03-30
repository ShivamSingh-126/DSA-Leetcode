class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int>arr(26,0);
        for(char &ch : sentence)
        {
            int idx=ch - 'a';
            arr[idx]++;
        }
        for(int &cnt : arr)
        {
            if(cnt == 0)
            {
                return false;
            }
        }
        return true;
    }
};