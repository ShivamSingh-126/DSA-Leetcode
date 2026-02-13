class Solution {
public:
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