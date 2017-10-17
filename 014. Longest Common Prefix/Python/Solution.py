class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''
        first_str = strs[0]
        common_index = 0
        while True:
            for str in strs:
                if len(str) == common_index or str[common_index] != first_str[common_index]:
                    return first_str[0:common_index]
            common_index += 1
