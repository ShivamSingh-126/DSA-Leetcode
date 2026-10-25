# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        in_map={}
        for i in range(len(inorder)):
            in_map[inorder[i]]=i

        self.root_idx = len(postorder)-1


        def build(left,right):
            if left > right:
                return None
            
            root_val = postorder[self.root_idx]
            self.root_idx -= 1

            root = TreeNode(root_val)

            mid = in_map[root_val]

            root.right = build(mid+1,right)

            root.left = build(left,mid-1)

            return root

        return build(0, len(inorder) - 1)

