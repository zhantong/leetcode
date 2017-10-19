class Solution:
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = {}
        for word in words:
            if word not in counts:
                counts[word] = 0
            counts[word] += 1
        heap = []
        for word, count in counts.items():
            heapq.heappush(heap, (-count, word))
        result = []
        for i in range(k):
            if not heap:
                break
            result.append(heapq.heappop(heap)[1])
        return result
