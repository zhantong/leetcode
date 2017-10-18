# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """


class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        stack = []
        current = NestedInteger()
        i = 0
        length = len(s)
        while i < length:
            if s[i] == '[':
                stack.append(current)
                current = NestedInteger()
                i += 1
            elif s[i] in '-0123456789':
                sign = 1
                if s[i] == '-':
                    sign = -1
                    i += 1
                num = 0
                while i < length and s[i] not in ',]':
                    num = num * 10 + ord(s[i]) - ord('0')
                    i += 1
                num = NestedInteger(num * sign)
                current.add(num)
            elif s[i] == ',':
                i += 1
            elif s[i] == ']':
                stack[-1].add(current)
                current = stack.pop()
                i += 1
        return current.getList()[0]
