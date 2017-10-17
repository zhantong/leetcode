class Solution:
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        positions = [0] * (len(flowers) + 1)
        for day, position in enumerate(flowers):
            positions[position] = day + 1
        start = 1
        end = start + k + 1
        if end >= len(positions):
            return -1
        result = sys.maxsize
        for position in range(1, len(positions)):
            day = positions[position]
            if positions[start] > day or positions[end] >= day:
                if position == end:
                    result = min(result, max(positions[start], positions[end]))
                start = position
                end = start + k + 1
                if end >= len(positions):
                    break
        return -1 if result == sys.maxsize else result
