# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode | None) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        nextRight = None
        
        def dfs(root):
            nonlocal nextRight

            if root is None:
                return

            dfs(root.right)

            dfs(root.left) 
            
            root.left = None

            root.right = nextRight

            nextRight = root

        dfs(root)