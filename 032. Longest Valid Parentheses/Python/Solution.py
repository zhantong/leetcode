class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        right = 0
        result = 0
        for item in s:
            if item == '(':
                left += 1
            else:
                right += 1
            if left == right:
                result = max(result, left + right)
            elif left < right:
                left = 0
                right = 0
        left = 0
        right = 0
        for item in reversed(s):
            if item == '(':
                left += 1
            else:
                right += 1
            if left == right:
                result = max(result, left + right)
            elif left > right:
                left = 0
                right = 0
        return result
