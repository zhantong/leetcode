class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        tokens_1 = version1.split('.')
        tokens_2 = version2.split('.')
        length_1 = len(tokens_1)
        length_2 = len(tokens_2)
        for i in range(max(length_1, length_2)):
            in_int_1 = int(tokens_1[i]) if i < length_1 else 0
            in_int_2 = int(tokens_2[i]) if i < length_2 else 0
            if in_int_1 > in_int_2:
                return 1
            elif in_int_1 < in_int_2:
                return -1
        return 0
