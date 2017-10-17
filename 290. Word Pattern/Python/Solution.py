class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        if len(pattern) != len(words):
            return False
        map = {}
        for letter, word in zip(pattern, words):
            if letter in map:
                if map[letter] != word:
                    return False
            else:
                if word in map.values():
                    return False
                map[letter] = word
        return True
