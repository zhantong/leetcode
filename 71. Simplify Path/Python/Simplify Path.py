class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for item in path.split('/'):
            if item == '' or item == '.':
                continue
            if item == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(item)
        result = '/'.join(stack)
        result = '/' + result
        return result
