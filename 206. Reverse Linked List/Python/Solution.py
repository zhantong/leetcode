# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head
        new_head = head
        while head.next is not None:
            current = head.next
            head.next = head.next.next
            current.next = new_head
            new_head = current
        return new_head
