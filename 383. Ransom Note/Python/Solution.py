class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        has = {}
        for item in magazine:
            if item not in has:
                has[item] = 0
            has[item] += 1
        for item in ransomNote:
            if item not in has or has[item] == 0:
                return False
            has[item] -= 1
        return True
