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
        if not s:
            return None
        if s[0] != '[':
            return NestedInteger(int(s))
        prev_index = 0
        index = 0
        stack = []
        current = None
        while index < len(s):
            if s[index] == '[':
                if current:
                    stack.append(current)
                current = NestedInteger()
                prev_index = index + 1
            if s[index] == ',':
                if s[index - 1] != ']':
                    item = int(s[prev_index:index])
                    current.add(NestedInteger(item))
                prev_index = index + 1
            if s[index] == ']':
                if s[index - 1] != ']' and s[index - 1] != '[':
                    item = int(s[prev_index:index])
                    current.add(NestedInteger(item))
                if stack:
                    outer = stack.pop()
                    outer.add(current)
                    current = outer
            index += 1
        return current
