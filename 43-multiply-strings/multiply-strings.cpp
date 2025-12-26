class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int x = num1.size();
        int y = num2.size();

        vector<int> ans(x+y,0);

        for(int i=x-1;i>=0;i--)
        {
            for(int j=y-1;j>=0;j--)
            {
                int prod=(num1[i]-'0')*(num2[j]-'0');
                int sum=prod + ans[i+j+1];

                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string res = "";
        int i = 0;
        while (i < ans.size() && ans[i] == 0)
            i++;
        while (i < ans.size())
            res.push_back(ans[i++] + '0');

        return res;
    }
};