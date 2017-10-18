# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        fake_head.next = head
        start = fake_head
        n -= m
        m -= 1
        while m:
            start = start.next
            m -= 1
        current = start.next
        while n:
            temp = start.next
            start.next = current.next
            current.next = current.next.next
            start.next.next = temp
            n -= 1
        return fake_head.next
