class Solution {
public:
    bool chkvowel(char ch)
    {
        ch=tolower(ch);
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    bool halvesAreAlike(string s) 
    {
        /*
        int n=s.size();
        int cnt1=0;
        int cnt2=0;

        for(int i=0;i<n/2;i++)
        {
            if(s[i] =='a' || s[i] == 'A' || s[i] =='e' || s[i] == 'E' || s[i] =='i' || s[i] == 'I' || s[i] =='o' || s[i] == 'O' || s[i] =='u' || s[i] == 'U')
            {
                cnt1++;
            }
        }
        //
                for(int i=n/2;i<n;i++)
        {
            if(s[i] =='a' || s[i] == 'A' || s[i] =='e' || s[i] == 'E' || s[i] =='i' || s[i] == 'I' || s[i] =='o' || s[i] == 'O' || s[i] =='u' || s[i] == 'U')
            {
                cnt2++;
            }
        }
        return (cnt1 == cnt2) ? true : false;
        */
        int n=s.length();
        int count=0;
        for(int i=0;i<n/2;i++)
        {
            if(chkvowel(s[i])) count++;
            if(chkvowel(s[i + n/2])) count--;
        }
        return count == 0;
    }
};