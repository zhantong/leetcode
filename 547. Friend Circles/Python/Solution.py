class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
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

        length = len(M)
        union_find = UnionFind(length)
        for i in range(length):
            for j in range(i + 1, length):
                if M[i][j]:
                    union_find.union(i, j)
        return union_find.count
