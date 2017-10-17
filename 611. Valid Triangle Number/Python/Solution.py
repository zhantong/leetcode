class Solution:
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        nums.sort()
        for i in range(2, len(nums)):
            first = 0
            second = i - 1
            while first < second:
                if nums[first] + nums[second] > nums[i]:
                    result += second - first
                    second -= 1
                else:
                    first += 1
        return result
