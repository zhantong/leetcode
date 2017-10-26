class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def parenthesis(result, current, left, right):
            if left == 0 and right == 0:
                result.append(current)
            elif left >= 0 and right >= left:
                parenthesis(result, current + '(', left - 1, right)
                parenthesis(result, current + ')', left, right - 1)

        result = []
        parenthesis(result, '', n, n)
        return result
