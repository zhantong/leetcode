class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = 0
        for point_a in points:
            distances = {}
            for point_b in points:
                distance = (point_a[0] - point_b[0]) ** 2 + (point_a[1] - point_b[1]) ** 2
                distances[distance] = distances.get(distance, 0) + 1
            result += sum(item * (item - 1) for item in distances.values())
        return result
