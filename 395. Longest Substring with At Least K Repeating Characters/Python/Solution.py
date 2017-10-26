class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def substring(s, k, start, end):
            if start >= end:
                return 0
            counts = [0] * 26
            for i in range(start, end):
                counts[ord(s[i]) - ord('a')] += 1
            sub_start = start
            max_length = -1
            for i in range(start, end):
                if counts[ord(s[i]) - ord('a')] < k:
                    sub_length = substring(s, k, sub_start, i)
                    sub_start = i + 1
                    max_length = max(max_length, sub_length)
            if sub_start != start:
                sub_length = substring(s, k, sub_start, end)
                max_length = max(max_length, sub_length)
            if max_length == -1:
                return end - start
            return max_length

        return substring(s, k, 0, len(s))
