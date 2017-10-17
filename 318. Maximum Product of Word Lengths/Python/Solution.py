class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        bits = []
        result = 0
        a_in_ascii = ord('a')
        for word in words:
            bit = 0
            for letter in word:
                bit |= 1 << (ord(letter) - a_in_ascii)
            bits.append(bit)
        for i in range(len(bits)):
            for j in range(i + 1, len(bits)):
                if not bits[i] & bits[j] and len(words[i]) * len(words[j]) > result:
                    result = len(words[i]) * len(words[j])
        return result
