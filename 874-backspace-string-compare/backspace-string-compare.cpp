class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        /*
        stack<char>st1;
        stack<char>st2;

        for(char ch : s)
        {
           if(ch == '#')
            {
                if(!st1.empty())
                {
                    st1.pop();
                }
            }
            else
            {
                st1.push(ch);
            }
        }
        for(char ch : t)
        {
            if(ch == '#')
            {
                if(!st2.empty())
                {
                    st2.pop();
                }
            }
            else
            {
                st2.push(ch);
            }
        }
        if(st1.size() != st2.size()) return false;

        while(!st1.empty())
        {
            if(st1.top() != st2.top())
            {
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
        */
        int i = s.size()-1, j = t.size()-1;
        int skips=0,skipt=0;

        while(i >=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i] == '#')
                {
                    skips++;
                    i--;
                }
                else if(skips > 0)
                {
                    skips--;
                    i--;
                }
                else   
                {
                    break;
                }
            }

            while(j>=0)
            {
                if(t[j] == '#')
                {
                    skipt++;
                    j--;
                }
                else if(skipt > 0)
                {
                    skipt--;
                    j--;
                }
                else   
                {
                    break;
                }
            }

            if(i >=0 && j>= 0)
            {
                if(s[i] != t[j])
                {
                    return false;
                }
            }
            else
            {
                if(i >= 0 || j>= 0)
                {
                    return false;
                }
            }
            i--;
            j--;
        }
        return true;
    }
};