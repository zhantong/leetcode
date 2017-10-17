class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        stack = []
        max_length = 0
        for item in input.split('\n'):
            count_tabs = item.rfind('\t') + 1
            while len(stack) > count_tabs:
                stack.pop()
            length = (stack[-1] if stack else 0) + len(item) - count_tabs + 1
            if '.' in item:
                max_length = max(max_length, length - 1)
            stack.append(length)
        return max_length
