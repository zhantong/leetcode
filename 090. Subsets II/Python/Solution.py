class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        nums.sort()
        last_start = 0
        for i, num in enumerate(nums):
            start = last_start if (i > 0 and nums[i] == nums[i - 1]) else 0
            last_start = len(result)
            for item in result[start:last_start]:
                temp = item[:]
                temp.append(num)
                result.append(temp)
        return result
