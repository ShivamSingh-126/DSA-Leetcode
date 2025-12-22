/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
         vector<vector<int>> mat(m, vector<int>(n, -1));

        int sr = 0, er = m - 1;
        int sc = 0, ec = n - 1;

        while ( sr <= er && sc <= ec) {

            // left → right (starting row)
            for (int j = sc; j <= ec && head; j++) {
                if(head==NULL)  break;
                mat[sr][j] = head->val;
                head = head->next;
            }
            sr++;

            // top → bottom (ending column)
            for (int i = sr; i <= er ; i++) {
                if(head==NULL)  break;
                mat[i][ec] = head->val;
                head = head->next;
            }
            ec--;

            // right → left (ending row)
            for (int j = ec; j >= sc ; j--) {
                if(head==NULL)  break;
                mat[er][j] = head->val;
                head = head->next;
            }
            er--;

            // bottom → top (starting column)
            for (int i = er; i >= sr; i--) {
                if(head==NULL)  break;
                mat[i][sc] = head->val;
                head = head->next;
            }
            sc++;
        }

        return mat;
    }
};