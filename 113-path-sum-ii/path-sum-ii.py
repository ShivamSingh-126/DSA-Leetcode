# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        def solve(root,targetSum,sum,result,temp):
            if root is None:
                return

            sum += root.val
            temp.append(root.val)

            if root.left is None and root.right is None:
                if sum == targetSum:
                    result.append(temp[:])
            
            solve(root.left,targetSum,sum,result,temp)
            solve(root.right,targetSum,sum,result,temp)

            temp.pop()

        result = []
        temp = []
        
        solve(root,targetSum,0,result,temp)
        return result
        
