class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        memory = [0] * 128
        for letter in t:
            memory[ord(letter)] += 1
        count = len(t)
        min_length = sys.maxsize
        min_start = 0
        start = 0
        i = 0
        while i < len(s):
            letter = ord(s[i])
            if memory[letter] > 0:
                count -= 1
            memory[letter] -= 1
            i += 1
            while count == 0:
                if i - start < min_length:
                    min_start = start
                    min_length = i - start
                memory[ord(s[start])] += 1
                if memory[ord(s[start])] > 0:
                    count += 1
                start += 1
        return '' if min_length == sys.maxsize else s[min_start:min_start + min_length]
