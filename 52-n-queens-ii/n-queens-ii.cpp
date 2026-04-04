class Solution {
public:
    unordered_map<int,bool>hc;
    unordered_map<int,bool>ldc;
    unordered_map<int,bool>udc;
    bool isPossible(vector<string>board,int row,int col)
    {
        if(hc[row]  == true)   return false;
        if(ldc[row+col] == true)  return false;
        if(udc[row-col] == true)  return false;

        return true;
    }
    void solve(vector<vector<string>> &res,vector<string>&board,int n,int col)
    {
        if(col >= n)
        {
            res.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isPossible(board,row,col))
            {
                board[row][col] = 'Q';
                hc[row] =true;
                ldc[row+col] =true;
                udc[row-col]=true;
                solve(res,board,n,col+1);

                board[row][col] = '.';
                hc[row] =false;
                ldc[row+col] =false;
                udc[row-col]=false;
            }
        }
    }
    int totalNQueens(int n) 
    {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        int col=0;
        solve(res,board,n,col);
        return res.size();
    }
};