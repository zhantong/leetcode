class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.result = 0

        def count(s, left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                self.result += 1
                left -= 1
                right += 1

        for i in range(len(s)):
            count(s, i, i)
            count(s, i, i + 1)
        return self.result
