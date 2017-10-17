class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        length = len(str)
        index = 0
        sign = 1
        result = 0
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        while index < length and str[index] == ' ':
            index += 1
        if index < length and str[index] == '-':
            sign = -1
            index += 1
        elif index < length and str[index] == '+':
            index += 1
        while index < length and str[index] >= '0' and str[index] <= '9':
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and ord(str[index]) - ord('0') > 7):
                if sign > 0:
                    return INT_MAX
                else:
                    return INT_MIN
            result = result * 10 + ord(str[index]) - ord('0')
            index += 1
        return sign * result
