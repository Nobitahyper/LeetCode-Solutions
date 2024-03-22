# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return
        
        stack, visited, res = [root], [False], []
        
        while stack:
            top = stack[-1]
            top_visited = visited[-1]
            
            if top_visited:
                stack.pop()
                visited.pop()
                res.append(top.val)
                
                
            else:
                visited[-1] = True
                
                if top.right:
                    stack.append(top.right)
                    visited.append(False)
                    
                if top.left:
                    stack.append(top.left)
                    visited.append(False)
                    
        return res