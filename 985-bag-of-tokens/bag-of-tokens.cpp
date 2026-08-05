class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();

        sort(tokens.begin(),tokens.end());

        int maxscore = 0;
        int score=0;
        int i=0,j=n-1;

        while(i <= j)
        {
            if(power >= tokens[i])  // Dec power and inc Score
            {
                power -= tokens[i];
                score++;
                i++;
                maxscore = max(maxscore,score);
            }
            else if(score >= 1)   // Inc power and Dec score 
            {
                power += tokens[j];
                score--;
                j--;
            }
            else
            {
                return maxscore;
            }
        }
        return maxscore;
    }
};