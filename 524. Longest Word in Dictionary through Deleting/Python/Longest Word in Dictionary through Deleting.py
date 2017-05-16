class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        d.sort(cmp=lambda a, b: cmp(a, b) if len(a) == len(b) else len(b) - len(a))
        for word in d:
            i = 0
            for letter in s:
                if letter == word[i]:
                    i += 1
                if i == len(word):
                    break
            if i == len(word):
                return word
        return ''
