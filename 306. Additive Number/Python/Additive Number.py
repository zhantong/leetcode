class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """

        def is_additive(second, third, num):
            if num[second] == '0' and third - second > 1:
                return False
            first = 0
            while third < len(num):
                a = int(num[first:second])
                b = int(num[second:third])
                the_sum = a + b
                the_sum = str(the_sum)
                if not num[third:].startswith(the_sum):
                    return False
                first = second
                second = third
                third += len(the_sum)
            return True

        for second in range(1, len(num)):
            if num[0] == '0' and second > 1:
                continue
            for third in range(second + 1, len(num)):
                if second <= len(num) - third and third - second <= len(num) - third:
                    if is_additive(second, third, num):
                        return True
        return False
