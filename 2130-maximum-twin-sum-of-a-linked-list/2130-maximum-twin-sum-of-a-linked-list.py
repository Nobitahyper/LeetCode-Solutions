# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        
        
        # find the middle node for second half
        slow, fast = head, head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
          
        
        # reverse the second half
        prev = None
        curr = slow
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
                
                
        # traverse thru both half and calculate the sum
        l1, l2 = head, prev
        max_sum = 0
        
        while l1 and l2:
            max_sum = max(max_sum, l1.val + l2.val)
            
            l1 = l1.next
            l2 = l2.next
        
        return max_sum