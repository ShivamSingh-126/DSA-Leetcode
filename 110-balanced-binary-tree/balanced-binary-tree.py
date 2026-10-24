# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if root is None:
            return True

        def getHeight(root):
            if root is None:
                return True

            leftht = getHeight(root.left)+1
            rightht=getHeight(root.right)+1

            return max(leftht,rightht)
        
        lefthtt=getHeight(root.left)
        righthtt=getHeight(root.right)

        if abs(lefthtt-righthtt) > 1:
            return False
        else:
            leftans=self.isBalanced(root.left)
            rightans=self.isBalanced(root.right)
        
        return leftans and rightans
