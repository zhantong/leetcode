class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        length = len(citations)
        counts = [0] * (length + 1)
        for citation in citations:
            if citation >= length:
                counts[length] += 1
            else:
                counts[citation] += 1
        paper_sum = 0
        for i in range(len(counts) - 1, -1, -1):
            paper_sum += counts[i]
            if paper_sum >= i:
                return i
        return 0
