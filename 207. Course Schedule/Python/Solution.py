class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = [[] * numCourses for i in range(numCourses)]
        in_degrees = [0] * numCourses
        for prerequisite in prerequisites:
            before = prerequisite[1]
            after = prerequisite[0]
            if after not in graph[before]:
                in_degrees[after] += 1
                graph[before].append(after)
        queue = []
        for index, in_degree in enumerate(in_degrees):
            if in_degree == 0:
                queue.append(index)
        count = 0
        while queue:
            current = queue.pop()
            count += 1
            for i in graph[current]:
                in_degrees[i] -= 1
                if in_degrees[i] == 0:
                    queue.append(i)
        return count == numCourses
