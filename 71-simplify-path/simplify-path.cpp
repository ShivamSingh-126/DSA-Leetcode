class Solution {
public:
    string simplifyPath(string path) 
    {
        /*
        // Using stack
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
        */
        
        // Using Vector
        string token="";
        stringstream sp(path);
        vector<string> st;

        while(getline(sp,token,'/'))
        {
            if(token == "" || token ==".")
            {
                continue;
            }
            if(token != ".." )
            {
               st.push_back(token);
            }
            else if(!st.empty())
            {
                st.pop_back();
            }
        }
        if(st.empty())  return "/";

        string res="";
        for(auto &token : st)
        {
            res = res + "/" + token;
        }
        return res;
    }
};