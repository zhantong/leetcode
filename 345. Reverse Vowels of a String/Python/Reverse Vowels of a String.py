class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        i = 0
        j = len(s) - 1
        string = list(s)
        while i < j:
            if string[i] not in vowels:
                i += 1
            elif string[j] not in vowels:
                j -= 1
            else:
                if string[i] != string[j]:
                    string[i], string[j] = string[j], string[i]
                i += 1
                j -= 1
        return ''.join(string)
