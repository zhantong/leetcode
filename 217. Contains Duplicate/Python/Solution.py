class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        contains = {}
        for num in nums:
            if num not in contains:
                contains[num] = 1
            else:
                return True
        return False
