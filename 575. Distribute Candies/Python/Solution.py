class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        nums = set(candies)
        num_nums = len(nums)
        target_num = len(candies) // 2
        return target_num if num_nums >= target_num else num_nums
