# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        fake_head.next = head
        tail = fake_head
        current = fake_head
        while True:
            count = k
            while count and tail:
                tail = tail.next
                count -= 1
            if not tail:
                break
            temp_head = current.next
            while current.next != tail:
                node = current.next
                current.next = node.next
                node.next = tail.next
                tail.next = node
            current = temp_head
            tail = temp_head
        return fake_head.next
