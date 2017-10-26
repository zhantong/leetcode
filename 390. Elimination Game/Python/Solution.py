class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        def left_to_right(n):
            if n == 1:
                return n
            return 2 * right_to_left(n // 2)

        def right_to_left(n):
            if n == 1:
                return n
            if n % 2:
                return 2 * left_to_right(n // 2)
            return 2 * left_to_right(n // 2) - 1

        return left_to_right(n)
