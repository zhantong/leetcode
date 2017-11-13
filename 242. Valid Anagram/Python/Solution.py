class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        counts = [0] * 26
        for item in s:
            counts[ord(item) - ord('a')] += 1
        for item in t:
            counts[ord(item) - ord('a')] -= 1
        return all(count == 0 for count in counts)
