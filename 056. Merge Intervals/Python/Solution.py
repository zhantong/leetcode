# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []
        intervals.sort(key=lambda item: item.start)
        start = intervals[0].start
        end = intervals[0].end
        result = []
        for interval in intervals:
            if interval.start > end:
                result.append(Interval(start, end))
                start = interval.start
            end = max(end, interval.end)
        result.append(Interval(start, end))
        return result
