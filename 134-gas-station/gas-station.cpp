class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int totalgas=0,totalcost=0;

        int curgas=0,start=0;
        
        for(int i=0;i<gas.size();i++)
        {
            totalgas+=gas[i];
            totalcost+=cost[i];
            curgas+=(gas[i]-cost[i]);

            if(curgas<0)
            {
                start=i+1;
                curgas=0;
            }
        }
        return (totalgas<totalcost) ? -1 : start;

        return start;
    }
};