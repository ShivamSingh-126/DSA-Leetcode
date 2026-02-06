class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        int n=nums1.size();
        vector<int> res(n,-1);
        int m=nums2.size();
        for(int j=0;j<n;j++)
        {
            int x=-1;
            for(int i=0;i<m;i++)
            {
                if(nums1[j] == nums2[i])
                {
                    x=i;
                    break;
                }
            }
            int k=x+1;
            while(k<m)
            {
                if(nums2[k] > nums1[j])
                {
                    res[j]=nums2[k];
                    break;
                }
                k++;              
            }
        }
        return res;
        */
        unordered_map<int,int> mp;
        stack<int> st;
        for(int val :nums2)
        {
            while(!st.empty() && st.top() < val)
            {
                mp[st.top()] = val;
                st.pop();
            }
            st.push(val);
        }
        vector<int> ans;
        for(int val :nums1)
        {
            ans.push_back(mp.count(val) ? mp[val] : -1);
        }
        return ans;
    }
};