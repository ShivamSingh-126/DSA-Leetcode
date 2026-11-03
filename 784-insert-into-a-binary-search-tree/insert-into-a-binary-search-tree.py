# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
        
        #Recursive Approach

        # if root is None:
        #     return TreeNode(val)

        # if val < root.val:
        #     root.left = self.insertIntoBST(root.left,val)
        
        # else:
        #     root.right = self.insertIntoBST(root.right,val)

        # return root


        new_node = TreeNode(val)

        if root is None:
            return new_node

        current = root
        
        while root:

            if val < current.val:
                if current.left is None:
                    current.left = new_node
                    break
                
                current = current.left

            else:
                if current.right is None:
                    current.right = new_node
                    break

                current = current.right

        return root