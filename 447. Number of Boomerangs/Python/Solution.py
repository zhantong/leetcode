class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = 0
        for point_a in points:
            distances = {}
            for point_b in points:
                distance = (point_a[0] - point_b[0])**2 + (point_a[1] - point_b[1])**2
                if distance not in distances:
                    distances[distance] = 0
                distances[distance] += 1
            for item in distances.values():
                result += item * (item - 1)
        return result
