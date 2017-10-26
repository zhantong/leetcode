class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        first_got = set()
        second_got = set()
        pattern = {
            'A': 0,
            'C': 1,
            'G': 2,
            'T': 3
        }
        result = []
        for i in range(len(s) - 9):
            current = 0
            for j in range(i, i + 10):
                current <<= 2
                current |= pattern[s[j]]
            if current not in first_got:
                first_got.add(current)
            elif current not in second_got:
                result.append(s[i:i + 10])
                second_got.add(current)
        return result
