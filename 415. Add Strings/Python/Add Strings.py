class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i = len(num1) - 1
        j = len(num2) - 1
        result = ''
        carry = 0
        while i >= 0 or j >= 0:
            plus = 0
            if i >= 0:
                plus += ord(num1[i]) - ord('0')
            if j >= 0:
                plus += ord(num2[j]) - ord('0')
            plus += carry
            result += chr(plus % 10 + ord('0'))
            carry = plus // 10
            i -= 1
            j -= 1
        if carry:
            result += '1'
        return result[::-1]
