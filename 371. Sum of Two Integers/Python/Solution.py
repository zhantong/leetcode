class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        mask = 0xffffffff
        sum = (a ^ b) & mask
        part = a & b
        print(bin(sum & mask), bin(part & mask), bin(a & mask), bin(b & mask))
        while part:
            a = sum
            b = (part << 1) & mask
            sum = (a ^ b) & mask
            part = a & b
        if sum & 0x80000000:
            sum -= 0x100000000
        return sum
