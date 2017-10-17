class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count_dict = {}
        count_pair = 0
        is_odd_exists = False
        for item in s:
            if item not in count_dict:
                count_dict[item] = 0
            count_dict[item] += 1
        for item in count_dict.values():
            count_pair += item // 2
            if not is_odd_exists:
                if item % 2 != 0:
                    is_odd_exists = True
        return count_pair * 2 + (1 if is_odd_exists else 0)
