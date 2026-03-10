class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int,int> mp;

        for(int &num :nums)
        {
            int x=((num % value) + value) % value;
            mp[x]++;
        }
        int mex=0;

        while(mp[(mex % value)] > 0)
        {
            mp[(mex % value)]-- ;

            mex++;
        }
        return mex;
    }
};