# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        back = None
        head = head
        old_head = None
        while not head is None:
            old_head = head
            head = head.next
            old_head.next = back
            back = old_head
        return old_head
