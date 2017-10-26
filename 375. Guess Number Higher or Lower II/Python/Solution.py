class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        def get_money(start, end, memory):
            if start >= end:
                return 0
            if memory[start][end] != 0:
                return memory[start][end]
            result = sys.maxsize
            for i in range(start, end + 1):
                current = i + max(get_money(start, i - 1, memory), get_money(i + 1, end, memory))
                result = min(result, current)
            memory[start][end] = result
            return result

        memory = [[0] * (n + 1) for _ in range(n + 1)]
        return get_money(0, n, memory)
