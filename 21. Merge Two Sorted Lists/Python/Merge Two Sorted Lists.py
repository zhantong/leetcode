# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if (not l1) and (not l2):
            return None
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val > l2.val:
            l1, l2 = l2, l1
        p = l1
        while p:
            while l2 and (p.next is None or l2.val < p.next.val):
                tmp = l2
                l2 = l2.next
                tmp.next = p.next
                p.next = tmp
                p = p.next
            p = p.next
        return l1
