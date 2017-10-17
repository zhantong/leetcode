class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first = -sys.maxsize
        second = first
        third = second
        for num in nums:
            if num > first:
                first, second, third = num, first, second
            elif num > second and num < first:
                second, third = num, second
            elif num > third and num < second:
                third = num
        if third == -sys.maxsize:
            return first
        return third
