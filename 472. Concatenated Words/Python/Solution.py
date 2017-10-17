class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        words_set = set()
        words.sort(key=lambda x: len(x))
        for word in words:
            if words_set:
                length = len(word)
                dp = [False] * (length + 1)
                dp[0] = True
                for i in range(length + 1):
                    for j in range(i):
                        if not dp[j]:
                            continue
                        if word[j:i] in words_set:
                            dp[i] = True
                            break
                if dp[length]:
                    result.append(word)
            words_set.add(word)
        return result
