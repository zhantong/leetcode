class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        mask = 0
        for i in range(31, -1, -1):
            mask |= 1 << i
            nums_set = set()
            for num in nums:
                nums_set.add(num & mask)
            current = result | (1 << i)
            for num in nums_set:
                if num ^ current in nums_set:
                    result = current
                    break
        return result
