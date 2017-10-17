class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 4:
            return False
        sum_nums = sum(nums)
        if sum_nums % 4:
            return False
        edges = [sum_nums // 4] * 4
        nums.sort(reverse=True)

        def square(nums, edges, start):
            if start == len(nums):
                return edges[0] == 0 and edges[1] == 0 and edges[2] == 0 and edges[3] == 0
            current = nums[start]
            for index, edge in enumerate(edges):
                if edge >= current:
                    edges[index] -= current
                    if square(nums, edges, start + 1):
                        return True
                    edges[index] += current
            return False

        return square(nums, edges, 0)
