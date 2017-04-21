class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        counts = [0] * 128
        for letter in s:
            counts[ord(letter)] += 1
        exists = [False] * 128
        for letter in s:
            letter_in_int = ord(letter)
            counts[letter_in_int] -= 1
            if exists[letter_in_int]:
                continue
            while stack and letter_in_int < stack[-1] and counts[stack[-1]] > 0:
                temp = stack.pop()
                exists[temp] = False
            stack.append(letter_in_int)
            exists[letter_in_int] = True
        return ''.join(map(chr, stack))
