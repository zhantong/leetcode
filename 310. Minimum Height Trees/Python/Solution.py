class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        graph = [set() for i in range(n)]
        for edge in edges:
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])
        remain = set(range(n))
        to_delete = set(i for i in remain if len(graph[i]) == 1)
        while len(remain) > 2:
            temp = set()
            for item in to_delete:
                remain.remove(item)
                for neighbor in graph[item]:
                    graph[neighbor].remove(item)
                    if len(graph[neighbor]) == 1 and neighbor in remain:
                        temp.add(neighbor)
            to_delete = temp
        return list(remain)
