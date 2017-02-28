class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        if not timeSeries:
            return 0
        result = duration
        for i in range(1, len(timeSeries)):
            result += duration
            gain = duration - (timeSeries[i] - timeSeries[i - 1])
            if gain > 0:
                result -= gain
        return result
