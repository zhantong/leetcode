# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        middle = slow
        current = middle.next
        while current.next:
            after = current.next
            current.next = after.next
            after.next = middle.next
            middle.next = after
        p = head
        while p != middle:
            temp = middle.next
            middle.next = temp.next
            temp.next = p.next
            p.next = temp
            p = p.next.next
