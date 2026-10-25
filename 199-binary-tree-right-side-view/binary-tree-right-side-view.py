# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        rv = []
        def rightview(root,level):
            if root is None:
                return 
            
            if len(rv) == level:
                rv.append(root.val)
            rightview(root.right , level+1)
            rightview(root.left , level+1)

        rightview(root,0)
        return rv
        