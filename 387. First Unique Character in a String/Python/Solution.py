class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counts = [0] * 26
        for item in s:
            counts[ord(item) - ord('a')] += 1
        for (index, item) in enumerate(s):
            if counts[ord(item) - ord('a')] == 1:
                return index
        return -1
