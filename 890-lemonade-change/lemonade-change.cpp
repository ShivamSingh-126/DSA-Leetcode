class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int n=bills.size();
        int f=0 , t=0 , tw = 0 ;

        for(int num : bills)
        {
            if(num == 5)
            {
                f++;
            }
            else if(num == 10)
            {
                t++;
                if(f > 0)
                {
                    f--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(f > 0 && t > 0)
                {
                    f--;
                    t--;
                }
                else if(f >= 3)
                {
                    f -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};