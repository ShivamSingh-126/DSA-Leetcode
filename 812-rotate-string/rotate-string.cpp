class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size()!=goal.size())  return false; // size !equal
        string check=s+s;   //create double string adding ++

        return check.find(goal)!=string ::npos; //// check if goal is a substring of check string 
    }
};