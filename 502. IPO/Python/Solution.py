class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        heap_capical = []
        heap_profit = []
        for capital, profit in zip(Capital, Profits):
            heapq.heappush(heap_capical, (capital, profit))
        for i in range(k):
            while heap_capical and heap_capical[0][0] <= W:
                item = heapq.heappop(heap_capical)
                heapq.heappush(heap_profit, -item[1])
            if not heap_profit:
                break
            W += -heapq.heappop(heap_profit)
        return W
