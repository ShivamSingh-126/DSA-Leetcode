class Solution {
public:
    int minSteps(string s, string t) 
    {
        /*
        int n=s.length();
        int maps[26]={0};
        int mapt[26]={0};

        for(int i=0;i<n;i++)
        {
            maps[s[i]-'a']++;
            mapt[t[i]-'a']++;
        }

        int ans=0;

        for(int i=0;i<26;i++)
        {
            if(maps[i] > mapt[i])
            ans+=maps[i]-mapt[i];
        }
        return ans;
        */
        int n=s.length();
        int mp[26]={0};

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }

        int ans=0;

        for(int i=0;i<26;i++)
        {
            if(mp[i] > 0)
            ans+=mp[i];
        }
        return ans;
    }
};