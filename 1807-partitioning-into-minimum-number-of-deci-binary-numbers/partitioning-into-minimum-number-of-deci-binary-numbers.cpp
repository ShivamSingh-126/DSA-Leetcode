class Solution {
public:
    int minPartitions(string n) 
    {
        /*
        int maxi=0;
        for(char ch : n)
        {
            maxi=max(maxi,ch-'0');
        }
        return maxi;
        */
        char maxele= *max_element(n.begin(),n.end());

        return maxele- '0';
    }
};