# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Find middle
        slow = fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        # Reverse 2nd half
        prev, curr = None, slow
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
            
        
        # Reorder the list
        
        l1, l2 = head, prev
        
        
        while l2.next:
            temp1 = l1.next
            temp2 = l2.next
            
            l1.next = l2
            if temp1 is None:
                break
            l2.next = temp1
            
            l1 = temp1 
            l2 = temp2
        
        
        
        