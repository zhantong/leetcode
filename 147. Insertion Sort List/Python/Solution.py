# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        fake_head = ListNode(0)
        fake_head.next = head
        prev = fake_head
        current = head
        while current.next:
            if current.next.val < current.val:
                while prev.next and prev.next.val < current.next.val:
                    prev = prev.next
                temp = prev.next
                prev.next = current.next
                current.next = current.next.next
                prev.next.next = temp
                prev = fake_head
            else:
                current = current.next

        return fake_head.next
