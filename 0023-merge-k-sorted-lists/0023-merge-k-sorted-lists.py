# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        minHeap = []
        # Custom comparator for the heap to compare ListNode objects
        ListNode.__lt__ = lambda self, other: self.val < other.val
        
        for l in lists:
            if l:
                heapq.heappush(minHeap, l)
                
        dummy = ListNode(0)
        current = dummy
        
        while minHeap:
            node = heapq.heappop(minHeap)
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(minHeap, node.next)
                
        return dummy.next
        