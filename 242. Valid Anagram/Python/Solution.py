class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        checkDict = {}
        for item in s:
            if item not in checkDict:
                checkDict[item] = 0
            checkDict[item] += 1
        for item in t:
            if item not in checkDict:
                return False
            checkDict[item] -= 1
        for value in checkDict.values():
            if value != 0:
                return False
        return True
