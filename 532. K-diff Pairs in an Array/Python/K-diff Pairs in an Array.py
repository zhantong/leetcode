class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0:
            return 0
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1
        result = 0
        for key, value in counts.items():
            if k == 0:
                if value >= 2:
                    result += 1
            else:
                if key + k in counts:
                    result += 1
        return result
