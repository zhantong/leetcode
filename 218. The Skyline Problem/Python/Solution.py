class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """

        def merge(buildings, low, high):
            result = []
            if low == high:
                result.append((buildings[low][0], buildings[low][2]))
                result.append((buildings[low][1], 0))
            elif low < high:
                mid = (low + high) // 2
                lefts = merge(buildings, low, mid)
                rights = merge(buildings, mid + 1, high)
                height_left = 0
                height_right = 0
                while lefts or rights:
                    current_left = lefts[0][0] if lefts else sys.maxsize
                    current_right = rights[0][0] if rights else sys.maxsize
                    current = 0
                    if current_left < current_right:
                        current, height_left = lefts.pop(0)
                    elif current_left > current_right:
                        current, height_right = rights.pop(0)
                    else:
                        current, height_left = lefts.pop(0)
                        current, height_right = rights.pop(0)
                    height = max(height_left, height_right)
                    if not result or result[-1][1] != height:
                        result.append([current, height])
            return result

        return merge(buildings, 0, len(buildings) - 1)
