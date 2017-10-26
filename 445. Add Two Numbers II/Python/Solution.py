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
        length_1 = 0
        temp = l1
        while temp:
            length_1 += 1
            temp = temp.next
        length_2 = 0
        temp = l2
        while temp:
            length_2 += 1
            temp = temp.next

        def two_numbers(l1, l2, length_1, length_2, result):
            node = ListNode(0)
            result.next = node
            if not l1.next:
                sum_two = l1.val + l2.val
            elif length_1 > length_2:
                carry = two_numbers(l1.next, l2, length_1 - 1, length_2, result.next)
                sum_two = l1.val + carry
            else:
                carry = two_numbers(l1.next, l2.next, length_1 - 1, length_2 - 1, result.next)
                sum_two = l1.val + l2.val + carry
            node.val = sum_two % 10
            return sum_two // 10

        result = ListNode(0)
        carry = two_numbers(l1, l2, length_1, length_2, result) if length_1 > length_2 else two_numbers(l2, l1,
                                                                                                        length_2,
                                                                                                        length_1,
                                                                                                        result)
        if carry:
            result.val = 1
        else:
            result = result.next
        return result
