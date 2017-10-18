# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return None
        walker = head
        runner = head
        while runner and runner.next:
            walker = walker.next
            runner = runner.next.next
            if walker == runner:
                break
        if runner is None or runner.next is None:
            return None
        walker = head
        while walker != runner:
            walker = walker.next
            runner = runner.next
        return walker
