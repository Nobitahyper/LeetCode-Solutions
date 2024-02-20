# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        prev = None
        curr = slow
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
                
        l1, l2 = head, prev
        max_sum = 0
        
        while l1 and l2:
            cur_sum = l1.val + l2.val
            max_sum = max(max_sum, cur_sum)
            
            l1 = l1.next
            l2 = l2.next
        
        return max_sum