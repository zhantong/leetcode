class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        words = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        result = ''
        for i in range(len(words)):
            while num >= values[i]:
                result += words[i]
                num -= values[i]
        return result
