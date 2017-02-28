class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        freq_dict = {}
        max_freq = -1
        for letter in s:
            if letter not in freq_dict:
                freq_dict[letter] = 0
            freq_dict[letter] += 1
            max_freq = max(max_freq, freq_dict[letter])
        freq_list = [None] * (max_freq + 1)
        for letter, freq in freq_dict.items():
            if not freq_list[freq]:
                freq_list[freq] = [letter]
            else:
                freq_list[freq].append(letter)
        result = ''
        for index in range(len(freq_list) - 1, 0, -1):
            letters = freq_list[index]
            if letters:
                for letter in letters:
                    result += letter * index
        return result
