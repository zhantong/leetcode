# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        slow = head
        fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None
        a = self.sortList(head)
        b = self.sortList(slow)
        fake_head = ListNode(0)
        temp = fake_head
        while a and b:
            if a.val < b.val:
                temp.next = a
                a = a.next
            else:
                temp.next = b
                b = b.next
            temp = temp.next
        if a:
            temp.next = a
        else:
            temp.next = b
        return fake_head.next
