class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        x1 = sys.maxsize
        y1 = sys.maxsize
        x2 = -sys.maxsize
        y2 = -sys.maxsize
        got = set()
        sum_up = 0
        for rectangle in rectangles:
            a1 = rectangle[0]
            b1 = rectangle[1]
            a2 = rectangle[2]
            b2 = rectangle[3]
            x1 = min(x1, a1)
            y1 = min(y1, b1)
            x2 = max(x2, a2)
            y2 = max(y2, b2)
            sum_up += (a2 - a1) * (b2 - b1)
            for i in [0, 2]:
                for j in [1, 3]:
                    key = str(rectangle[i]) + ' ' + str(rectangle[j])
                    if key in got:
                        got.remove(key)
                    else:
                        got.add(key)
        return len(got) == 4 \
            and (str(x1) + ' ' + str(y1)) in got \
            and (str(x1) + ' ' + str(y2)) in got \
            and (str(x2) + ' ' + str(y1)) in got \
            and (str(x2) + ' ' + str(y2)) in got \
            and sum_up == (x2 - x1) * (y2 - y1)
