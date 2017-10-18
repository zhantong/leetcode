class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = list(str(n))
        length = len(s)
        i = len(s) - 2
        while i >= 0:
            if s[i] < s[i + 1]:
                break
            i -= 1
        if i == -1:
            return -1
        j = i + 1
        smallest = '9'
        smallest_index = -1
        while j < length:
            if s[j] > s[i] and s[j] < smallest:
                smallest = s[j]
                smallest_index = j
            j += 1
        s[i], s[smallest_index] = s[smallest_index], s[i]
        print(s)
        s[i + 1:] = sorted(s[i + 1:])
        n = int(''.join(s))
        if n > 0x7fffffff:
            return -1
        return n
