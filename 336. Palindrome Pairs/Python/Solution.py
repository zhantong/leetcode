class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        result = []
        words_set = {k: v for v, k in enumerate(words)}
        for i, word in enumerate(words):
            for j in range(len(word) + 1):
                left = word[:j]
                right = word[j:]
                if right[::-1] in words_set and words_set[right[::-1]] != i and left == left[::-1]:
                    result.append([words_set[right[::-1]], i])
                if left[::-1] in words_set and words_set[left[::-1]] != i and right == right[::-1] and right:
                    result.append([i, words_set[left[::-1]]])
        return result
