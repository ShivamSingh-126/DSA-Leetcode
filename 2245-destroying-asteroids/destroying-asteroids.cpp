class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long curmass = mass;

        for(int i=0;i<n;i++)
        {
            if(curmass < asteroids[i])
            {
                return false;
            }
            curmass += asteroids[i];
        }
        return true;
    }
};