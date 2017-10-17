class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        pattern_dict = {}
        for item in p:
            if item not in pattern_dict:
                pattern_dict[item] = 0
            pattern_dict[item] += 1
        false_alarm = 0
        match_count = len(p)
        p_length = len(p)
        result = []
        for right in range(0, len(s)):
            left = right - p_length
            if left >= 0 and s[left] in pattern_dict:
                if pattern_dict[s[left]] == -1:
                    false_alarm -= 1
                pattern_dict[s[left]] += 1
                match_count += 1
            if s[right] in pattern_dict:
                if pattern_dict[s[right]] == 0:
                    false_alarm += 1
                pattern_dict[s[right]] -= 1
                match_count -= 1
                if match_count == 0 and false_alarm == 0:
                    result.append(left + 1)
        return result
