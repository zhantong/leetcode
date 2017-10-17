class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        nums = set(candies)
        nums_num = len(nums)
        target_num = len(candies) // 2
        if nums_num >= target_num:
            return target_num
        return nums_num