class Solution(object):
    def __init__(self):
        self.index = 0

    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = ''
        while self.index < len(s) and s[self.index] != ']':
            letter = s[self.index]
            if letter.isnumeric():
                count = 0
                while self.index < len(s) and s[self.index].isnumeric():
                    count = count * 10 + int(s[self.index])
                    self.index += 1
                self.index += 1
                sub_str = self.decodeString(s)
                self.index += 1
                for i in range(count):
                    result += sub_str
            else:
                result += letter
                self.index += 1
        return result
