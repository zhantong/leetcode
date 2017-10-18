# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        walker = head
        runner = head.next
        while walker and runner and runner.next:
            walker = walker.next
            runner = runner.next.next
            if walker == runner:
                return True
        return False
