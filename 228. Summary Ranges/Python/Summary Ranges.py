class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []
        start = 0
        offset = nums[0]
        result = []
        for i in range(1, len(nums)):
            if i + offset != nums[i]:
                if start == i - 1:
                    result.append(str(nums[start]))
                else:
                    result.append('%d->%d' % (nums[start], nums[i - 1]))
                offset = nums[i] - i
                start = i
        if start == len(nums) - 1:
            result.append(str(nums[start]))
        else:
            result.append('%d->%d' % (nums[start], nums[-1]))
        return result
