class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = {}
        starts = {}
        ends = {}
        max_count = -sys.maxsize
        for i, num in enumerate(nums):
            if num not in starts:
                starts[num] = i
                counts[num] = 0
            counts[num] += 1
            ends[num] = i
            max_count = max(max_count, counts[num])
        result = sys.maxsize
        for num, count in counts.items():
            if count == max_count:
                result = min(result, ends[num] - starts[num] + 1)
        return result
