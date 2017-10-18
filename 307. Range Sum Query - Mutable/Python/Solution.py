class NumArray(object):
    class Node:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            self.left = None
            self.right = None
            self.sum = 0

    def build(self, nums, start, end):
        if start > end:
            return None
        node = self.Node(start, end)
        if start == end:
            node.sum = nums[start]
        else:
            mid = (start + end) // 2
            node.left = self.build(nums, start, mid)
            node.right = self.build(nums, mid + 1, end)
            node.sum = node.left.sum + node.right.sum
        return node

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.root = self.build(nums, 0, len(nums) - 1)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """

        def upd(node, i, val):
            if node.start == node.end:
                node.sum = val
            else:
                mid = (node.start + node.end) // 2
                if i <= mid:
                    upd(node.left, i, val)
                else:
                    upd(node.right, i, val)
                node.sum = node.left.sum + node.right.sum

        upd(self.root, i, val)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """

        def sum_ran(node, start, end):
            if node.start == start and node.end == end:
                return node.sum
            mid = (node.start + node.end) // 2
            if end <= mid:
                return sum_ran(node.left, start, end)
            if start > mid:
                return sum_ran(node.right, start, end)
            return sum_ran(node.left, start, mid) + sum_ran(node.right, mid + 1, end)

        return sum_ran(self.root, i, j)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
