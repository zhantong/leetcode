class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """

        def dfs(graph, i, order, visiting, visited):
            visiting[i] = True
            visited[i] = True
            for neighbor in graph[i]:
                if visiting[neighbor]:
                    return False
                if not visited[neighbor]:
                    if not dfs(graph, neighbor, order, visiting, visited):
                        return False
            order.append(i)
            visiting[i] = False
            return True

        order = []
        visiting = [False] * numCourses
        visited = [False] * numCourses
        graph = {}
        for i in range(numCourses):
            graph[i] = []
        for line in prerequisites:
            graph[line[1]].append(line[0])
        for i in range(numCourses):
            if not visited[i]:
                if not dfs(graph, i, order, visiting, visited):
                    return []
        return list(reversed(order))
