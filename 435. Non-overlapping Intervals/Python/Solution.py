# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e


class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        count = 0
        current_end = -sys.maxsize
        intervals.sort(key=lambda item: item.end)
        for interval in intervals:
            if interval.start >= current_end:
                current_end = interval.end
                count += 1
        return len(intervals) - count
