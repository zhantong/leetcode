class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        counts = [0] * 26
        current_max = 0
        for i in range(len(p)):
            if i > 0 and ord(p[i]) - ord(p[i - 1]) == 1 or ord(p[i - 1]) - ord(p[i]) == 25:
                current_max += 1
            else:
                current_max = 1
            index = ord(p[i]) - ord('a')
            counts[index] = max(counts[index], current_max)
        return sum(counts)
