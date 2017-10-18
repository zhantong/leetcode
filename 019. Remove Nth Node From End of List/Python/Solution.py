# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        first = head
        second = head
        prev = head
        while n:
            first = first.next
            n -= 1
        while first:
            first = first.next
            prev = second
            second = second.next
        if second == head:
            return head.next
        prev.next = prev.next.next
        return head
