class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        has = [0] * 26
        for item in magazine:
            has[ord(item) - ord('a')] += 1
        for item in ransomNote:
            if has[ord(item) - ord('a')] == 0:
                return False
            has[ord(item) - ord('a')] -= 1
        return True
