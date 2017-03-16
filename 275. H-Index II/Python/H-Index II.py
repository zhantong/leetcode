class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0
        length = len(citations)
        low = 0
        high = length - 1
        while low <= high:
            mid = (low + high) // 2
            if citations[mid] == length - mid:
                return length - mid
            if citations[mid] < length - mid:
                low = mid + 1
            else:
                high = mid - 1
        return length - low
