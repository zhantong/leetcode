# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e


class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        result = []
        starts = [interval.start for interval in intervals]
        starts.sort()
        indexs = {}
        for index, interval in enumerate(intervals):
            indexs[interval.start] = index
        for interval in intervals:
            end = interval.end
            low = 0
            high = len(starts) - 1
            while low <= high:
                mid = (low + high) // 2
                if starts[mid] < end:
                    low = mid + 1
                else:
                    high = mid - 1
            if low == len(starts):
                result.append(-1)
            else:
                result.append(indexs[starts[low]])
        return result
