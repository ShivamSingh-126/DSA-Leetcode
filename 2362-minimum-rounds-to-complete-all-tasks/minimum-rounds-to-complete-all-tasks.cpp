class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int,int>mpp;
        for(int num : tasks)
        {
            mpp[num]++;
        }
        int count=0;
        for(auto val : mpp)
        {
            if(val.second <= 1)  return -1;
            else
            {
                if(val.second % 3 ==0)
                {
                    count += val.second/3;
                }
                else
                {
                    count += (val.second / 3)+1;
                }
            }
        }
        return count;
    }
};