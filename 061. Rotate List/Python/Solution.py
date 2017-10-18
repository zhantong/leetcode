# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head
        tail = head
        length = 1
        while tail.next:
            tail = tail.next
            length += 1
        if k % length:
            tail.next = head
            step = length - k % length - 1
            new_head = head
            for i in range(step):
                new_head = new_head.next
            head = new_head.next
            new_head.next = None
        return head
