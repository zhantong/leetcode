# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        fake_head.next = head
        greater = fake_head
        while greater.next and greater.next.val < x:
            greater = greater.next
        current = greater.next
        while current and current.next:
            if current.next.val < x:
                temp = greater.next
                greater.next = current.next
                current.next = current.next.next
                greater.next.next = temp
                greater = greater.next
            else:
                current = current.next
        return fake_head.next
