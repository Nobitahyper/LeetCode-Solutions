# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def dfs(node, path_bitmask):
            if not node:
                return 0
            
            path_bitmask ^= 1 << node.val
            
            if not node.left and not node.right:
                if path_bitmask & (path_bitmask - 1) == 0:
                    return 1
                else:
                    return 0
                
            return dfs(node.left, path_bitmask) + dfs(node.right, path_bitmask)
        
        return dfs(root, 0)
        
        



