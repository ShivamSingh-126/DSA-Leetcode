
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """

        # Store each value's index in inorder
        in_map = {}

        for i in range(len(inorder)):
            in_map[inorder[i]] = i

        # Tracks the next root in preorder
        self.pre_idx = 0

        def build(left, right):
            # No nodes in this subtree
            if left > right:
                return None

            # Preorder gives us the root
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1

            root = TreeNode(root_val)

            # Find the root's position in inorder
            mid = in_map[root_val]

            # Build left subtree first
            root.left = build(left, mid - 1)

            # Then build right subtree
            root.right = build(mid + 1, right)

            return root

        return build(0, len(inorder) - 1)
