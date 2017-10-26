class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        def pow(a, n, base):
            result = 1
            for _ in range(n):
                result = (result * a) % base
            return result

        if not b:
            return 1
        last = b.pop()
        base = 1337
        return pow(self.superPow(a, b), 10, base) * pow(a, last, base) % base
