class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        result = 0
        left = -1
        for i, letter in enumerate(s):
            if letter == '(':
                stack.append(i)
            else:
                if not stack:
                    left = i
                else:
                    stack.pop()
                    result = max(result, i - (stack[-1] if stack else left))
        return result
