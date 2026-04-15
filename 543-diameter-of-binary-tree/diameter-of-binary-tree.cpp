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
      int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftnode=maxDepth(root->left) +1;
        int rightnode=maxDepth(root->right) +1;

        int count=max(leftnode,rightnode);
        return count;
        
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;            
        }
        int rootnode=maxDepth(root->left)+maxDepth(root->right);
        int leftnode=diameterOfBinaryTree(root->left);
        int rightnode=diameterOfBinaryTree(root->right);

        int count=max(rootnode,max(leftnode,rightnode));
        return count;
    }
};