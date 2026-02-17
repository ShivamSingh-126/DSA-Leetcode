class Solution {
public:
    string simplifyPath(string path) 
    {
        string token="";
        stringstream sp(path);
        stack<string> st;

        while(getline(sp,token,'/'))
        {
            if(token == "" || token ==".")
            {
                continue;
            }
            if(token != ".." )
            {
               st.push(token);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }
        if(st.empty())  return "/";

        string res="";
        while(!st.empty())
        {
            res="/"+ st.top() + res;
            st.pop();
        }
        return res;
    }
};