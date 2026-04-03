class Solution {
public:
    unordered_map<int,bool>hc;
    unordered_map<int,bool>ldc;
    unordered_map<int,bool>udc;
    bool isPossible(int row,int col,vector<vector<char>> &board)
    {
        int n=board.size();
        // we need to check only 3 direction

                    // left horizontal
        // for(int i=0;i<col;i++)
        // {
        //     if(board[row][i] == 'Q')
        //     {
        //         return false;   // that means one queen attack on another queen
        //     }
        // }
            if(hc[row] == true) return false;
            
                    // left upper diagonal
        // int i=row-1;
        // int j=col-1;
        // while(i>=0 && j>=0)
        // {
        //     if(board[i][j] == 'Q')
        //     {
        //         return false;   // that means one queen attack on another queen
        //     }
        //     i--,j--;
        // }
        if(udc[row-col] == true)  return false;

                    //left lower diagonals 
        // int x=row+1;
        // int y=col-1;
        // while(x<n && y>=0)
        // {
        //     if(board[x][y] == 'Q')
        //     {
        //         return false;   // that means one queen attack on another queen
        //     }
        //     x++,y--;
        // }
        if(ldc[row+col] == true)  return false;

        return true;
    }

    void solution(vector<vector<char>> &board,vector<vector<string>> &ans,int n)
    {
        vector<string> temp;
        for(int row=0;row<n;row++)
        {
            string output="";
            for(int col=0;col<n;col++)
            {
                char ch=board[row][col];
                output.push_back(ch);   // put each char into output string
            }
            temp.push_back(output);  // crearte one path
        }
        ans.push_back(temp);    // temp fill with all string
    }
    void solve(vector<vector<char>> &board,vector<vector<string>> &ans,int n,int col)
    {
        // base case
        if(col >= n)
        {
            solution(board,ans,n);
            return ;            
        }
        // solve 1 case and other left on recursion
        for(int row=0;row < n ;row++)
        {
            if(isPossible(row,col,board))
            {
                board[row][col] = 'Q';
                hc[row] = true;
                ldc[row+col] = true;
                udc[row-col] = true;
                // call recursion for other
                solve(board,ans,n,col+1);
                //Backtracking
                board[row][col] = '.';
                hc[row] = false;
                ldc[row+col] = false;
                udc[row-col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(board, ans, n, col);
        return ans;
    }
};