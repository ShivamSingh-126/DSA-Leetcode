class Solution {
public:
    string addBinary(string a, string b) 
    {
        int st=a.size()-1;
        int end=b.size()-1;
        int sum=0;
        int carry=0;
        string ans="";

        while(st>=0 || end>=0 || carry)
        {
            sum=carry;
            if(st>=0)
            {
                sum+=a[st] - '0';
                st--;
            }
            if(end>=0)
            {
                sum+=b[end] - '0';
                end--;
            }
            ans.push_back(sum % 2 +'0');
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};