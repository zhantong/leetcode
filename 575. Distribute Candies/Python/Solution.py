class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        show_once = set(candies)
        show_once_num = len(show_once)
        target_num = len(candies) // 2
        if show_once_num >= target_num:
            return target_num
        return show_once_num
