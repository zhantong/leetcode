class Solution:
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """

        def addition(a, b):
            def gcd(x, y):
                return gcd(y % x, x) if x != 0 else y

            parts_a = a.split('/')
            parts_b = b.split('/')
            up = int(parts_a[0]) * int(parts_b[1]) + int(parts_a[1]) * int(parts_b[0])
            down = int(parts_a[1]) * int(parts_b[1])
            sign = ''
            if up < 0:
                sign = '-'
                up *= -1
            return sign + str(up // gcd(up, down)) + '/' + str(down // gcd(up, down))

        fractions = re.findall('[+-]?\d+/\d+', expression)
        result = '0/1'
        for fraction in fractions:
            result = addition(result, fraction)
        return result
