# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def tree_sum(root, sum_nodes, max_freq):
            if not root:
                return 0, max_freq
            sum_left, max_freq = tree_sum(root.left, sum_nodes, max_freq)
            sum_right, max_freq = tree_sum(root.right, sum_nodes, max_freq)
            sum_node = sum_left + sum_right + root.val
            if sum_node not in sum_nodes:
                sum_nodes[sum_node] = 0
            sum_nodes[sum_node] += 1
            return sum_node, max(max_freq, sum_nodes[sum_node])

        sum_nodes = {}
        temp, max_freq = tree_sum(root, sum_nodes, -1)
        result = []
        for (sum_node, freq) in sum_nodes.items():
            if freq == max_freq:
                result.append(sum_node)
        return result
