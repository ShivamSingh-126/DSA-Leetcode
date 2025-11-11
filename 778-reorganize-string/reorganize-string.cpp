class Solution {
public:
    string reorganizeString(string s) 
    {
        int hash[26]={0};

        for(int i=0;i<s.size();i++)
        {
            hash[s[i] -'a']++;
        }
        // searching most frequent character 
        char m_f_c;
        int m_f=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(hash[i] > m_f)
            {
                m_f=hash[i];
                m_f_c=i+'a';                
            }
        }
        // place the most frequent character alternate
        int index=0;
        while(m_f>0 && index<s.size())
        {
            s[index]=m_f_c;
            m_f--;
            index+=2;
        }

        if(m_f !=0)
        {
            return "";
        }

        hash[m_f_c-'a']=0;

        //place the rest of the character

        for(int i=0;i<26;i++)
        {
            while(hash[i] > 0)
            {
                index=index >= s.size() ? 1:index;
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
        }

        return s;
    }
};