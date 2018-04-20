# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.val > l2.val:
            l1, l2 = l2, l1
        p = l1
        while p is not None:
            while l2 is not None and (p.next is None or l2.val < p.next.val):
                tmp = l2
                l2 = l2.next
                tmp.next = p.next
                p.next = tmp
                p = p.next
            p = p.next
        return l1
