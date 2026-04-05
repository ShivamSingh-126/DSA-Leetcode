class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
       int m=word1.size();
       int n=word2.size();

        if(m != n)  return false;
       vector<int>freq1(26);
       vector<int>freq2(26);

       for(int i=0;i<n;i++)
       {
            char ch1=word1[i];
            int index1=ch1-'a';
            freq1[index1]++;

            char ch2=word2[i];
            int index2=ch2-'a';
            freq2[index2]++;
       }
       // check character in both the freq vector are same
       for(int i=0;i<26;i++)
       {
            if(freq1[i] != 0 && freq2[i] != 0)  continue;

            if(freq1[i] == 0 && freq2[i] == 0)  continue;

            return false;
       }
       sort(freq1.begin(),freq1.end());
       sort(freq2.begin(),freq2.end());

       return freq1 == freq2;       // frequency match
    }
};