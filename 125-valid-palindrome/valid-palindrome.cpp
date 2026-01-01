class Solution {
public:
    bool isPalindrome(string s) 
    {
        /*
        string st="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if((s[i] >='a' && s[i] <='z') || (s[i] >='A' && s[i] <='Z'))
            {
                st+=tolower(s[i]);
            }            
        }
        int start=0,end=st.size()-1;
        while(start<=end)
        {
            if(st[start] != st[end])
            return false;

            start++;
            end--;
        }
        return true;
        */
        int start = 0, end = s.size() - 1;

        while(start < end)
        {
            while(start < end && !isalnum(s[start])) start++;
            while(start < end && !isalnum(s[end])) end--;

            if(tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }
        return true;
    }
};