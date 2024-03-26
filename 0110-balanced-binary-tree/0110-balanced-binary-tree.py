# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        def height(node):
            if not node:
                return 0
            l_height = height(node.left)
            r_height = height(node.right)
        
            if l_height == -1 or r_height == -1 or abs(l_height - r_height) > 1:
                return -1
            
            return 1 + max(l_height, r_height)
        
        
        return height(root) != -1