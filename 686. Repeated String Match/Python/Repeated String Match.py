class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        temp = ''
        result = 0
        while len(temp) < len(B):
            temp += A
            result += 1
        if B in temp:
            return result
        temp += A
        result += 1
        if B in temp:
            return result
        return -1
