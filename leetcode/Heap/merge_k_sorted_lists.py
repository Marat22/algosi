# https://leetcode.com/problems/merge-k-sorted-lists/

import heapq

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i, node in enumerate(lists):
            if not node:
                continue
            heap.append( (node.val, i, node) )
        heapq.heapify(heap)

        res = ListNode()
        root = res
        while heap:
            val, i, node = heapq.heappop(heap)
            if node.next is not None:
                heapq.heappush(heap, (node.next.val, i, node.next) )
            res.next = node
            res = res.next
        return root.next
