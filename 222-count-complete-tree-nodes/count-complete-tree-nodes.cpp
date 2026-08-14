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
    int getleft(TreeNode* root)
    {
        TreeNode* temp = root;
        int lh = 0;

        while(temp)
        {
            lh++;
            temp = temp->left;
        }
        return lh;
    }
    int getright(TreeNode* root)
    {
        TreeNode* temp = root;
        int rh = 0;

        while(temp)
        {
            rh++;
            temp = temp->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) 
    {
        // O(n)
        /*
        if(root == NULL)  return 0;

        return 1+countNodes(root->left) + countNodes(root->right);
        */

        if(root ==NULL)  return 0;

        int lh = getleft(root);
        int rh = getright(root);

        if(lh == rh)
        {
            return (pow(2,lh)-1);
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};