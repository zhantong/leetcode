class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result = 0
        counts = [0] * 128
        left_index = 0
        current_max = 0
        for right_index, letter in enumerate(s):
            counts[ord(letter)] += 1
            current_max = max(current_max, counts[ord(letter)])
            while right_index - left_index + 1 - current_max > k:
                counts[ord(s[left_index])] -= 1
                left_index += 1
            result = max(result, right_index - left_index + 1)
        return result
