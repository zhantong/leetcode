class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for item in s:
            if item in ['(', '{', '[']:
                stack.append(item)
            elif not stack and item in [')', '}', ']']:
                return False
            elif item == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif item == '}':
                if stack[-1] == '{':
                    stack.pop()
                else:
                    return False
            elif item == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return False
        return not stack
