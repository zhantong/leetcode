class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        heights = []
        for building in buildings:
            heights.append((building[0], -building[2]))
            heights.append((building[1], building[2]))
        heights.sort()
        h = []
        heapq.heappush(h, 0)
        prev = 0
        result = []
        for height in heights:
            if height[1] < 0:
                heapq.heappush(h, height[1])
            else:
                h.remove(-height[1])
                heapq.heapify(h)
            current = -h[0]
            if prev != current:
                result.append((height[0], current))
                prev = current
        return result
