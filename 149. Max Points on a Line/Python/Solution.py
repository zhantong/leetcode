# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        def transform(a, b):
            def gcd(a, b):
                while b:
                    a, b = b, a % b
                return a

            c = gcd(a, b)
            a /= c
            b /= c
            return (a << 32) | b

        if len(points) < 3:
            return len(points)
        result = 0
        for i, current in enumerate(points):
            same_point = 1
            same_vertical_line = 0
            memory = {}
            for j in range(i + 1, len(points)):
                point = points[j]
                if current.x == point.x and current.y == point.y:
                    same_point += 1
                elif current.x == point.x:
                    same_vertical_line += 1
                else:
                    key = transform(point.y - current.y, point.x - current.x)
                    if key not in memory:
                        memory[key] = 0
                    memory[key] += 1
            result = max(result, same_vertical_line + same_point)
            if memory:
                result = max(result, max(memory.values()) + same_point)
        return result
