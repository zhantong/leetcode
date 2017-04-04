class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        rows = [''] * numRows
        index = 0
        while index < len(s):
            for i in range(numRows):
                if index < len(s):
                    rows[i] += s[index]
                    index += 1
            for i in range(numRows - 2, 0, -1):
                if index < len(s):
                    rows[i] += s[index]
                    index += 1
        return ''.join(rows)
