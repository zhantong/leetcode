class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        first = sys.maxsize
        second = sys.maxsize
        for num in nums:
            if num < first:
                first = num
            elif num < second and num > first:
                second = num
            elif num > second:
                return True
        return False
