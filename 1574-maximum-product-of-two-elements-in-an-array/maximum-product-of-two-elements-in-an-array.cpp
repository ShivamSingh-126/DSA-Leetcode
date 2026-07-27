class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int gr=-1;
        int sgr=-1;

        for(int num : nums)
        {
            if(num >= gr)
            {
                sgr=gr;
                gr=num;
            }
            else if(num >= sgr)
            {
                sgr=num;
            }
        }
        return (gr-1)*(sgr-1);
    }
};