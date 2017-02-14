class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count_dict = {}
        for item in s:
            if item not in count_dict:
                count_dict[item] = 0
            count_dict[item] += 1
        for (index, item) in enumerate(s):
            if count_dict[item] == 1:
                return index
        return -1
