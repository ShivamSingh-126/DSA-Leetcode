class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        hour %=12;
        double ans = abs((60.0 * hour) - (11.0 * minutes))/2.0;
        if(ans > 180)
        {
            ans = 360 - ans;
        }
        return ans;
    }
};