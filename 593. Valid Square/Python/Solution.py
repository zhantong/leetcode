class Solution:
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """

        def distance(p1, p2):
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

        distances = [distance(p1, p2), distance(p1, p3), distance(p1, p4), distance(p2, p3), distance(p2, p4),
                     distance(p3, p4)]
        distances.sort()
        return distances[0] == distances[1] == distances[2] == distances[3] < distances[4] == distances[5]
