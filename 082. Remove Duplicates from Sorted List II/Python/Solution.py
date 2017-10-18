# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        fake_head.next = head
        node = fake_head
        flag = False
        while node.next and node.next.next:
            if node.next.val == node.next.next.val:
                flag = True
                node.next.next = node.next.next.next
            else:
                if flag:
                    node.next = node.next.next
                    flag = False
                else:
                    node = node.next
        if flag:
            node.next = node.next.next
        return fake_head.next
