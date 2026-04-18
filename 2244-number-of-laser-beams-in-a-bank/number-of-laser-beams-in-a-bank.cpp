class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int m=bank.size();
        int n=bank[0].size();

        int prev=0;
        int curr=0;
        int sum=0;
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(bank[i][j] == '1')
                {
                    if(i==0) prev++;    //3
                    else
                    {
                        curr++;
                    }
                }                
            }
            if(curr > 0)
            {
                sum+=prev*curr;
                prev=curr;
                curr=0; 
            }
        }
        return sum;
    }
};