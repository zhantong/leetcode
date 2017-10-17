class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        counts = {}
        words_length = len(words)
        word_length = len(words[0])
        for word in words:
            if word not in counts:
                counts[word] = 0
            counts[word] += 1
        for i in range(len(s) - words_length * word_length + 1):
            current_counts = {}
            j = 0
            while j < words_length:
                index = i + j * word_length
                current = s[index:index + word_length]
                if current in counts:
                    if current not in current_counts:
                        current_counts[current] = 0
                    current_counts[current] += 1
                    if current_counts[current] > counts[current]:
                        break
                else:
                    break
                j += 1
            if j == words_length:
                result.append(i)
        return result
