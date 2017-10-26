# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        def partition(lists, start, end):
            if start == end:
                return lists[start]
            if start < end:
                mid = (start + end) // 2
                list_1 = partition(lists, start, mid)
                list_2 = partition(lists, mid + 1, end)
                return merge(list_1, list_2)
            return None

        def merge(list_1, list_2):
            fake_head = ListNode(0)
            current = fake_head
            while list_1 and list_2:
                if list_1.val < list_2.val:
                    current.next = list_1
                    list_1 = list_1.next
                else:
                    current.next = list_2
                    list_2 = list_2.next
                current = current.next
            current.next = list_1 if list_1 else list_2
            return fake_head.next

        return partition(lists, 0, len(lists) - 1)
