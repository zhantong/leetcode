class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        memory = {}
        result = 0
        j = 0
        for i, letter in enumerate(s):
            if letter in memory:
                j = max(j, memory[letter] + 1)
            memory[letter] = i
            result = max(result, i - j + 1)
        return result
