class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int totbot=0,embot=0,remb=0;
        while(numBottles>0)
        {
            totbot+=numBottles;
            // embot=numBottles;
            embot=numBottles+remb;
            numBottles=embot/numExchange;
            remb=embot%numExchange;
        }
        return totbot;
    }
};