class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        sum_nums = sum(nums)
        if S > sum_nums or S < -sum_nums:
            return 0
        map = [0] * (2 * sum_nums + 1)
        map[sum_nums] = 1
        for num in nums:
            new_map = [0] * (2 * sum_nums + 1)
            for i in range(2 * sum_nums + 1):
                if map[i]:
                    new_map[i + num] += map[i]
                    new_map[i - num] += map[i]
            map = new_map
        return map[sum_nums + S]
