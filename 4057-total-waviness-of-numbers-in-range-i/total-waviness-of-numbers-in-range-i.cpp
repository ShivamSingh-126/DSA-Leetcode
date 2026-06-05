class Solution {
public:
    int findwave(int num)
    {
        string s=to_string(num);
        int l=s.length();
        if(l<3)
        {
            return 0;
        }
        int score=0;
        for(int i=1;i<=l-2;i++)
        {
            if(s[i] > s[i-1] && s[i] > s[i+1])      //peak
            {
                score++;
            }
            if(s[i] < s[i-1] && s[i] < s[i+1])      //valley
            {
                score++;
            }
        }
        return score;
    }
    int totalWaviness(int num1, int num2) 
    {
        int count=0;

        for(int num=num1;num<=num2;num++)
        {
            count += findwave(num);
        }
        return count;
    }
};