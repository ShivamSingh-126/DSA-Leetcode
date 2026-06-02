class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n=fruits.size();
        unordered_map<int,int>mpp;

        int low=0;
        int res=0;

        for(int high=0;high<n;high++)
        {
            mpp[fruits[high]]++;

            while(mpp.size() > 2)
            {
                mpp[fruits[low]]--;

                if(mpp[fruits[low]] == 0)
                {
                    mpp.erase(fruits[low]);
                }
                low++;
            }

            res=max(res,high-low+1);
        }
        return res;
    }
};