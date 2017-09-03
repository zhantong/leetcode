class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        left = 0
        right = int(c ** 0.5)
        while left <= right:
            current = left * left + right * right
            if current == c:
                return True
            elif current < c:
                left += 1
            else:
                right -= 1
        return False
