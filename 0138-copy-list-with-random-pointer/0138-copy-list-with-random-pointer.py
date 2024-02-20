"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        # clone the new nodes right after originial
        # 1 - 1' - 2 - 2' - 3 - 3'
        curr = head
        while curr:
            new_node = Node(curr.val, curr.next, curr.random)
            curr.next = new_node
            curr = new_node.next
            
        
        # Update the random pointers for new nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            
            curr = curr.next.next
        
        # Separate the new and original list
        
        original, clone = head, head.next
        new_head = head.next
        
        while original:
            original.next = original.next.next
            clone.next = clone.next.next if clone.next else None
            original = original.next
            clone = clone.next
            
        return new_head
        
        
            
        
        
            
        