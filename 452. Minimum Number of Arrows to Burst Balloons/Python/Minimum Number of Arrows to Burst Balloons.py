class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda point: point[1])
        current_start = -sys.maxsize
        result = 0
        for point in points:
            if point[0] > current_start:
                current_start = point[1]
                result += 1
        return result
