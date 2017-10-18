# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        temp = fake_head
        carry = 0
        while l1 or l2:
            current = carry
            if l1:
                current += l1.val
                l1 = l1.next
            if l2:
                current += l2.val
                l2 = l2.next
            temp.next = ListNode(current % 10)
            temp = temp.next
            carry = current // 10
        if carry:
            temp.next = ListNode(carry)
        return fake_head.next
