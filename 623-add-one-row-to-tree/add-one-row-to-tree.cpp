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

    TreeNode* helper(TreeNode* root, int val, int depth,int curr)
    {
        if(root == NULL)  return NULL;

        if(curr == depth-1)
        {
            // Store the old children
            TreeNode* lefttemp = root->left;
            TreeNode* righttemp = root->right;


            // Create the new Node
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);


            // Attach the old node
            root->left->left = lefttemp;
            root->right->right = righttemp;

            return root;
        }
        // if not then recall for left and right
        root->left = helper(root->left,val,depth,curr+1);
        root->right = helper(root->right,val,depth,curr+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int curr = 1;

        return helper(root,val,depth,curr);

    }
};