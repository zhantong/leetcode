class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        results = [0] * (target + 1)
        results[0] = 1
        for i in range(1, target + 1):
            for num in nums:
                if i - num >= 0:
                    results[i] += results[i - num]
        return results[target]
