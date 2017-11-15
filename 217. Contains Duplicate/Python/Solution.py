class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        contains = set()
        for num in nums:
            if num in contains:
                return True
            contains.add(num)
        return False
