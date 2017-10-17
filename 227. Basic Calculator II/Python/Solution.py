class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        pre_number = 0
        pre_operator = '+'
        i = 0
        while i < len(s):
            while i < len(s) and s[i] == ' ':
                i += 1
            current = 0
            while i < len(s) and s[i] >= '0' and s[i] <= '9':
                current = current * 10 + ord(s[i]) - ord('0')
                i += 1
            if pre_operator == '+':
                result += pre_number
                pre_number = current
            elif pre_operator == '-':
                result += pre_number
                pre_number = -current
            elif pre_operator == '*':
                pre_number *= current
            else:
                temp = pre_number
                pre_number /= current
                if temp < 0 and temp % current:
                    pre_number += 1
            while i < len(s) and s[i] == ' ':
                i += 1
            if i < len(s):
                pre_operator = s[i]
                i += 1
        result += pre_number
        return result
