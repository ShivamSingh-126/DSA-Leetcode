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
    int maxsum;
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lsum = helper(root->left);
        int rsum = helper(root->right);

        int ans_below = lsum + rsum + root->val;

        int only_one_correct = max(lsum , rsum) + root->val;

        int only_root_correct = root->val;

        maxsum = max({maxsum,ans_below,only_one_correct,only_root_correct});

        return max(only_one_correct,only_root_correct);
    }
    int maxPathSum(TreeNode* root) 
    {
        maxsum = INT_MIN;
        helper(root);

        return maxsum;
    }
};