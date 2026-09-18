class Solution {
public:
    int helper(vector<int>& tops, vector<int>& bottoms,int val)
    {
        int n=tops.size();

        int swaptop = 0;
        int swapbottom = 0;

        for(int i=0;i<n;i++)
        {
            if(tops[i] != val && bottoms[i] != val)
            {
                return -1;
            }
            else if(tops[i] != val)
            {
                swaptop++;
            }
            else if(bottoms[i] != val)
            {
                swapbottom++;
            }
        }
        return min(swaptop,swapbottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int result = INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int swaps = helper(tops,bottoms,i);

            if(swaps != -1)
            {
                result = min(result,swaps);
            }
        }
        return result == INT_MAX ? -1 : result; 
    }
};