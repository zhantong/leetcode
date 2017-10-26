class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def dfs(result, current, n):
            if current > n:
                return
            result.append(current)
            current *= 10
            if current <= n:
                for i in range(10):
                    if current + i <= n:
                        dfs(result, current + i, n)

        result = []
        for i in range(1, 10):
            dfs(result, i, n)
        return result
