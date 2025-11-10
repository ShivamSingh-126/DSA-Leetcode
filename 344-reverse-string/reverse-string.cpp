class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // int st=0,end=s.size()-1;
        // for(int i=0;i<s.size()/2;i++)
        // {
        //     st=s[i];
        //     end=s[s.size()-i-1];
        //     s[i]=end;
        //     s[s.size()-i-1]=st;
        // }
        // reverse(s.begin(),s.end());
        int low=0,high=s.size()-1;
        while(low<=high)
        {
            swap(s[low++],s[high--]);
        }
    }
};