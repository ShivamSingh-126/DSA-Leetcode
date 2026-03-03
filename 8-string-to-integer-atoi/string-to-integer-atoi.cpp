class Solution {
public:
    int helper(string &s , int i, long long num,int sign)
    {
        int maxi=INT_MAX;
        int mini=INT_MIN;

        if( i >= s.size() || !isdigit(s[i]))
        {
            return (int)(sign*num);
        }

        num=num*10+(s[i] - '0');

        if(sign  * num >= maxi)  return INT_MAX;
        if(sign  * num <= mini)  return INT_MIN;

        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) 
    {
        /*
        int integer=atoi(s.c_str());
        return integer;
        */
        /*
        // Iterative Approach
        int num=0,i=0,sign=1;

        while(s[i]==' ')
        {
            i++;
        }
        
        if(i<s.size() && s[i]=='-' || s[i]=='+')
        {
            sign=s[i]=='+' ? 1 :-1;
            ++i;
        }

        while(i<s.size() && isdigit(s[i]))
        {
            if(num > INT_MAX /10 || (num== INT_MAX /10 && s[i] >'7'))
            {
                return sign==-1 ? INT_MIN: INT_MAX;
            }
            num = num*10+(s[i]-'0');
            ++i;
        }
        return num*sign;
        */
        //Recursive approach
        int i=0;
        while(i < s.size() && s[i] == ' ') i++;
        int sign=1;
        if(i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            sign=(s[i] == '+') ? 1 : -1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};