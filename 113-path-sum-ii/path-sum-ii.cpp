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
    vector<vector<int>> ans;

    void helper(TreeNode* root, int sum,vector<int>path,int &targetSum)
    {
        if(root == NULL)  return;

        sum+=root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL)   // if leaf node
        {
            if(sum == targetSum)
            {
                ans.push_back(path);
            }
            return;
        }
        helper(root->left,sum,path,targetSum);
        helper(root->right,sum,path,targetSum);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int>path;
        int sum=0;

        helper(root,sum,path,targetSum);
        return ans;
    }
};