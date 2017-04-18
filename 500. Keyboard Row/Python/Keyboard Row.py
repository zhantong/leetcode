class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        pattern = {}
        for letter in 'qwertyuiop':
            pattern[letter] = 1
        for letter in 'asdfghjkl':
            pattern[letter] = 2
        for letter in 'zxcvbnm':
            pattern[letter] = 3
        result = []
        for word in words:
            word_lower = word.lower()
            category = pattern[word_lower[0]]
            is_same_category = True
            for letter in word_lower:
                if pattern[letter] != category:
                    is_same_category = False
                    break
            if is_same_category:
                result.append(word)
        return result
