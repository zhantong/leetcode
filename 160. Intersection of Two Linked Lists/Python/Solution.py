# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        length_a = 0
        temp = headA
        while temp:
            temp = temp.next
            length_a += 1
        length_b = 0
        temp = headB
        while temp:
            temp = temp.next
            length_b += 1
        if length_a > length_b:
            for i in range(length_a - length_b):
                headA = headA.next
        if length_b > length_a:
            for i in range(length_b - length_a):
                headB = headB.next
        while headA != headB:
            headA = headA.next
            headB = headB.next
        return headA
