class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """

        def topological_sort(graph, n):
            order = []
            visiting = [False] * n
            visited = [False] * n
            for i in range(n):
                if not visited[i]:
                    if not dfs(graph, i, visiting, visited, order):
                        # raise ValueError('cycle')
                        return []
            order.reverse()
            return order

        def dfs(graph, index, visiting, visited, order):
            visiting[index] = True
            visited[index] = True
            for neighbor in graph[index]:
                if visiting[neighbor]:
                    return False
                if not visited[neighbor]:
                    if not dfs(graph, neighbor, visiting, visited, order):
                        return False
            order.append(index)
            visiting[index] = False
            return True

        graph = {}
        for i in range(numCourses):
            graph[i] = []
        for line in prerequisites:
            graph[line[1]].append(line[0])
        return topological_sort(graph, numCourses)
