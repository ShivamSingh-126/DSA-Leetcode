class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        vector<int> maxnum(10,0);
        int sum=-1;

        for(auto val : nums)
        {
            int maxdig=0;
            int dup=val;

            while(dup)
            {
                maxdig=max(maxdig,dup%10);  // find max digit
                dup=dup/10;
            }
            if(maxnum[maxdig])     // if max dig exist then update sum
            {
                sum=max(sum,maxnum[maxdig]+val);
            }

            if(val > maxnum[maxdig])   // not exist else update maxdig
            {
                maxnum[maxdig]=val;
            }
        }
        return sum;
    }
};