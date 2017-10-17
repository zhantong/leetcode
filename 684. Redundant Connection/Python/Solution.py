class Solution:
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        class UnionFind:
            def __init__(self, n):
                self.count = n
                self.parent = [i for i in range(n)]
                self.rank = [0] * n

            def find(self, num):
                if num != self.parent[num]:
                    self.parent[num] = self.find(self.parent[num])
                return self.parent[num]

            def union(self, a, b):
                parent_a = self.find(a)
                parent_b = self.find(b)
                if parent_a == parent_b:
                    return
                if self.rank[parent_a] > self.rank[parent_b]:
                    self.parent[parent_b] = parent_a
                else:
                    self.parent[parent_a] = parent_b
                    if self.rank[parent_a] == self.rank[parent_b]:
                        self.rank[parent_b] += 1
                self.count -= 1

        union_find = UnionFind(len(edges) + 1)
        for edge in edges:
            if union_find.find(edge[0]) == union_find.find(edge[1]):
                return edge
            union_find.union(edge[0], edge[1])
