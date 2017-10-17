class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if not nums:
            return nums
        m = len(nums)
        n = len(nums[0])
        if m * n < r * c:
            return nums
        new_nums = [[0] * c for _ in range(r)]
        for i in range(r * c):
            new_nums[i // c][i % c] = nums[i // n][i % n]
        return new_nums
