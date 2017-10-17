class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s1_length = len(s1)
        count = len(s1)
        memory = [0] * 26
        for letter in s1:
            memory[ord(letter) - ord('a')] += 1
        for i, letter in enumerate(s2):
            if memory[ord(letter) - ord('a')] > 0:
                count -= 1
                if count == 0:
                    return True
            memory[ord(letter) - ord('a')] -= 1
            if i >= s1_length - 1:
                left_index = i - s1_length + 1
                if memory[ord(s2[left_index]) - ord('a')] >= 0:
                    count += 1
                memory[ord(s2[left_index]) - ord('a')] += 1
        return False
