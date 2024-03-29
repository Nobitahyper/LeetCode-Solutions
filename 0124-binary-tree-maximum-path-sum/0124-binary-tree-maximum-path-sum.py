# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        res = [root.val]
        
        # function to calc max sum without split
        def dfs(root):
            if not root:
                return 0
            
            leftMax = dfs(root.left)
            rightMax = dfs(root.right)
            
            # Avoiding negative vals
            leftMax = max(leftMax, 0)
            rightMax = max(rightMax, 0)
            
            # computing the result with split
            res[0] = max(res[0], root.val + leftMax + rightMax)
            
            
            # returning the max sum without split
            
            return root.val + max(leftMax, rightMax)
        
        dfs(root)
        return res[0]