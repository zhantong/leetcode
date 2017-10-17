class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        the_sum = (C - A) * (D - B) + (G - E) * (H - F)
        left = max(A, E)
        right = min(C, G)
        up = min(D, H)
        down = max(B, F)
        if right > left and up > down:
            overlap = (right - left) * (up - down)
            return the_sum - overlap
        return the_sum
