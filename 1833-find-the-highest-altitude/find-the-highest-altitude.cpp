class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int sum=0;
        int high_alt=0;

        for(int num : gain)
        {
            sum += num;
            high_alt = max(high_alt,sum);
        }
        return high_alt;
    }
};