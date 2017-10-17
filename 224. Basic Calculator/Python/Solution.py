class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        result = 0
        current = 0
        sign = 1
        for letter in s:
            if letter.isdigit():
                current = current * 10 + ord(letter) - ord('0')
            elif letter in ['+', '-']:
                result += sign * current
                current = 0
                sign = 1 if letter == '+' else -1
            elif letter == '(':
                stack.append(result)
                stack.append(sign)
                sign = 1
                result = 0
            elif letter == ')':
                result += sign * current
                result *= stack.pop()
                result += stack.pop()
                current = 0
        result += sign * current
        return result
