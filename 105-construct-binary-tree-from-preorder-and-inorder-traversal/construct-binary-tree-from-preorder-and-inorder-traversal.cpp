/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx)
    {
        if(start > end)  return NULL;   // not exist

        int rootval = preorder[idx];    // taking 1st element of preorder as root element
        int i=start;

        for(; i<= end ;i++)
        {
            if(inorder[i] == rootval)
            {
                break;  // we find the rootval in inorder
            }
        }
        idx++;

        TreeNode* root = new TreeNode(rootval);
        root->left = helper(preorder,inorder,start,i-1,idx);    // call for root->left
        root->right = helper(preorder,inorder,i+1,end,idx);     // call for root->right

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();

        int idx=0;

        return helper(preorder,inorder,0,n-1,idx);
    }
};