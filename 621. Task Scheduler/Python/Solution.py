class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        letters = [0] * 26
        for letter in tasks:
            letters[ord(letter) - ord('A')] += 1
        letters.sort(reverse=True)
        i = 0
        while letters[i] == letters[0]:
            i += 1
        return max(len(tasks), (letters[0] - 1) * (n + 1) + i)
