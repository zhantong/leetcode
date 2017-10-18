# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        temp = None
        while slow:
            next = slow.next
            slow.next = temp
            temp = slow
            slow = next
        slow = temp
        while head and slow:
            if head.val != slow.val:
                return False
            head = head.next
            slow = slow.next
        return True
