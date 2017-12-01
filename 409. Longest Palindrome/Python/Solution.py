class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count_array = [0] * (ord('z') - ord('A') + 1)
        pair = 0
        is_odd_exists = False
        for item in s:
            count_array[ord(item) - ord('A')] += 1
        for item in count_array:
            pair += item // 2
            if not is_odd_exists:
                is_odd_exists = item % 2 != 0
        return pair * 2 + (1 if is_odd_exists else 0)
