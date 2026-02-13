class Solution {
public:/*
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    */
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        if(n==1)  return heights[0];
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;

        // right Arrays 
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            right[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // left array
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            left[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int width=right[i]-left[i]-1;
            int curarea=heights[i] * width;
            ans=max(ans,curarea);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty())  return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> hist(col,0);
        int maxi=0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='1')
                {
                    hist[j]++;
                }
                else
                {
                    hist[j]=0;
                }
            }
            maxi=max(maxi,largestRectangleArea(hist));
        }
        return maxi;
    }
};