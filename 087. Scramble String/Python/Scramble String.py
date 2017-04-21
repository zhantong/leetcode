class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1 == s2:
            return True
        if len(s1) != len(s2):
            return False
        length = len(s1)
        count = [0] * 26
        for l1, l2 in zip(s1, s2):
            count[ord(l1) - ord('a')] += 1
            count[ord(l2) - ord('a')] -= 1
        for item in count:
            if item:
                return False
        for i in range(1, length):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[length - i:]) and self.isScramble(s1[i:], s2[:length - i]):
                return True
        return False
