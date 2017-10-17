class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        count = {}
        for row in wall:
            current = 0
            for item in row[:-1]:
                current += item
                if current not in count:
                    count[current] = 0
                count[current] += 1
        return len(wall) - (max(count.values()) if count else 0)
