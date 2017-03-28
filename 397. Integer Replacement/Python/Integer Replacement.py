class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n > 1:
            if n % 2:
                if not (n + 1) % 4 and n != 3:
                    n += 1
                else:
                    n -= 1
            else:
                n //= 2
            count += 1
        return count
