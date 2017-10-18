# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return head
        memory = {}
        new_head = RandomListNode(head.label)
        current = head
        new_current = new_head
        memory[current] = new_current
        while current.next:
            new_current.next = RandomListNode(current.next.label)
            memory[current.next] = new_current.next
            new_current = new_current.next
            current = current.next
        current = head
        new_current = new_head
        while current:
            if current.random:
                new_current.random = memory[current.random]
            new_current = new_current.next
            current = current.next
        return new_head
