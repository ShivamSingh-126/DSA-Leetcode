class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) 
    {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());

        double cost=0;

        for(int i=0;i<prices.size();i++)
        {
            if(i < discounts.size())
            {
                cost += prices[i] * ((100.0 - discounts[i]) / 100.0);
            }
            else
            {
                cost += prices[i];
            }
        }
        return cost;
    }
};