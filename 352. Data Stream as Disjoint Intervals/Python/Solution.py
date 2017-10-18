# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e


class SummaryRanges(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intervals = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        intervals = self.intervals
        if not intervals:
            intervals.append(Interval(val, val))
        else:
            low = 0
            high = len(intervals) - 1
            while low < high:
                mid = (low + high) // 2
                if intervals[mid].start <= val and intervals[mid].end >= val:
                    return
                if intervals[mid].start > val:
                    high = mid
                else:
                    low = mid + 1
            current_interval = intervals[low]
            left_neighbor = intervals[low - 1] if low > 0 else None
            if current_interval.start <= val and val <= current_interval.end:
                return
            elif val < current_interval.start:
                if not left_neighbor:
                    if current_interval.start == val + 1:
                        current_interval.start = val
                    else:
                        intervals.insert(0, Interval(val, val))
                else:
                    if left_neighbor.end + 1 == current_interval.start - 1:
                        left_neighbor.end = current_interval.end
                        intervals.remove(current_interval)
                    else:
                        if left_neighbor.end + 1 == val:
                            left_neighbor.end = val
                        else:
                            if current_interval.start == val + 1:
                                current_interval.start = val
                            else:
                                intervals.insert(low, Interval(val, val))
            else:
                if current_interval.end + 1 == val:
                    current_interval.end = val
                else:
                    intervals.append(Interval(val, val))

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        return self.intervals


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
