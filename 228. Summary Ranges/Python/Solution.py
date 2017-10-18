class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        length = len(nums)
        result = []
        i = 0
        while i < length:
            j = i + 1
            while j < length and nums[j - 1] + 1 == nums[j]:
                j += 1
            if i + 1 == j:
                result.append(str(nums[i]))
            else:
                result.append(str(nums[i]) + "->" + str(nums[j - 1]))
            i = j
        return result
