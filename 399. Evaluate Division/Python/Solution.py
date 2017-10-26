class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        def dfs(start, end, graph, graph_value, current, current_value):
            if start in current or start not in graph:
                return 0.0
            if start == end:
                return current_value
            current.add(start)
            nodes = graph[start]
            values = graph_value[start]
            for i in range(len(nodes)):
                got = dfs(nodes[i], end, graph, graph_value, current, current_value * values[i])
                if got != 0.0:
                    current.remove(start)
                    return got
            current.remove(start)
            return 0.0

        result = [0.0] * len(queries)
        graph = {}
        graph_value = {}
        for equation, value in zip(equations, values):
            if equation[0] not in graph:
                graph[equation[0]] = []
                graph_value[equation[0]] = []
            graph[equation[0]].append(equation[1])
            graph_value[equation[0]].append(value)
            if equation[1] not in graph:
                graph[equation[1]] = []
                graph_value[equation[1]] = []
            graph[equation[1]].append(equation[0])
            graph_value[equation[1]].append(1.0 / value)
        for i, query in enumerate(queries):
            result[i] = dfs(query[0], query[1], graph, graph_value, set(), 1.0)
            if result[i] == 0.0:
                result[i] = -1.0
        return result
