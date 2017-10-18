class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """

        def is_valid(num, a, b, start):
            if start == len(num):
                return True
            a, b = b, a + b
            return num.startswith(str(b), start) and is_valid(num, a, b, start + len(str(b)))

        length = len(num)

        for i in range(1, length // 2 + 1):
            if i > 1 and num[0] == '0':
                return False
            first = int(num[:i])
            for j in range(i + 1, length + 1):
                if (j > i + 1 and num[i] == '0') or j - i > length - j:
                    break
                second = int(num[i:j])
                if is_valid(num, first, second, j):
                    return True
        return False
