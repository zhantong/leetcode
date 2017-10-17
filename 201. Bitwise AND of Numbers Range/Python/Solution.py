class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        the_xor = m ^ n
        diff_index = 31
        while diff_index >= 0 and not the_xor & 1 << diff_index:
            diff_index -= 1
        return m & 0xffffffff << (diff_index + 1)
