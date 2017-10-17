class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        if len(timePoints) > 1440:
            return 0
        buckets = [0] * 1440
        for point in timePoints:
            minutes = int(point[:2]) * 60 + int(point[3:])
            buckets[minutes] += 1
            if buckets[minutes] > 1:
                return 0
        result = sys.maxsize
        prev = -1440
        for i, bucket in enumerate(buckets):
            if bucket:
                result = min(result, i - prev)
                prev = i
        for i, bucket in enumerate(buckets):
            if bucket:
                result = min(result, 1440 + i - prev)
                break
        return result
