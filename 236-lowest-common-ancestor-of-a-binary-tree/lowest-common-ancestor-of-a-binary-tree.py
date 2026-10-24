# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        
        if root is p:
            return p
        if root is q:
            return q
        
        leftans = self.lowestCommonAncestor(root.left,p,q)
        rightans = self.lowestCommonAncestor(root.right,p,q)

        if leftans is None and rightans is None:
            return None
        elif leftans is not None and rightans is None:
            return leftans
        elif leftans is None and rightans is not None:
            return rightans
        else:
            return root