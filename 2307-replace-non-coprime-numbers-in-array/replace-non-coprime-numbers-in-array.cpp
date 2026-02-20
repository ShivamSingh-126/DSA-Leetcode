class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int> res;
        for(int num : nums)
        {
            while(!res.empty())
            {
                int pre=res.back();
                int curr=num;

                int GCD=gcd(pre,num);
                if(GCD == 1)  break;

                res.pop_back();

                int lcm=pre / GCD *curr;
                num=lcm;
            }
            res.push_back(num);
        }
        return res;
    }
};