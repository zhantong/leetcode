# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []


class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        def clone(node, memory):
            if node.label not in memory:
                copy = UndirectedGraphNode(node.label)
                memory[copy.label] = copy
                for neighbor in node.neighbors:
                    copy.neighbors.append(clone(neighbor, memory))
            return memory[node.label]
        if not node:
            return node
        memory = {}
        return clone(node, memory)
