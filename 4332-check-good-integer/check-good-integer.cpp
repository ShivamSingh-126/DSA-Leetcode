class Solution {
public:
    bool checkGoodInteger(int n) 
    {
        int digitsum =0;
        int squaresum =0;

        while(n > 0)
        {
            int rem = n % 10;
            digitsum += rem;
            squaresum += rem*rem;

            n /=10;
        }
        if(squaresum - digitsum >= 50)  return true;

        return false;
    }
};