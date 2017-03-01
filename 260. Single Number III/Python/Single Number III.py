class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        mixed_xor = 0
        for num in nums:
            mixed_xor ^= num
        diff = mixed_xor & (mixed_xor - 1) ^ mixed_xor
        first = 0
        second = 0
        for num in nums:
            if diff & num:
                first ^= num
            else:
                second ^= num
        return [first, second]
