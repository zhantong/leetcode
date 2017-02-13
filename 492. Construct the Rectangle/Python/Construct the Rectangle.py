class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        x = int(math.ceil(math.sqrt(area)))
        while area % x != 0:
            x += 1
        y = int(area / x)
        return [x, y]
