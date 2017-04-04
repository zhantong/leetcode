class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        i = 0
        while i < len(num) - 1 and k > 0:
            if num[i] > num[i + 1]:
                num = num[:i] + num[i + 1:]
                k -= 1
                if i > 0:
                    i -= 1
            else:
                i += 1
        while num and k > 0:
            num = num[:-1]
            k -= 1
        while num and num[0] == '0':
            num = num[1:]
        if not num:
            return '0'
        return num
