class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq_dict = {}
        max_freq = -1
        for num in nums:
            if num not in freq_dict:
                freq_dict[num] = 0
            freq_dict[num] += 1
            max_freq = max(max_freq, freq_dict[num])
        freq_list = [None] * (max_freq + 1)
        for num, freq in freq_dict.items():
            if not freq_list[freq]:
                freq_list[freq] = [num]
            else:
                freq_list[freq].append(num)
        result = []
        for freq in range(len(freq_list) - 1, 0, -1):
            if freq_list[freq] and len(result) < k:
                result += freq_list[freq]
        return result
