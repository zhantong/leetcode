class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        num_str = list(str(num))
        last_index = {}
        for i, item in enumerate(num_str):
            last_index[item] = i
        for i, item in enumerate(num_str):
            for digit in '987654321':
                if digit > item and digit in last_index and last_index[digit] > i:
                    num_str[i], num_str[last_index[digit]] = num_str[last_index[digit]], num_str[i]
                    return int(''.join(num_str))
        return num
