class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        def back_trace(s, word_dict, current, result, memory):
            if not s:
                result.append(' '.join(current))
                return ['']
            if s in memory:
                if memory[s]:
                    part = ' '.join(current)
                    for item in memory[s]:
                        result.append(part + ' ' + item)
                return memory[s]
            else:
                current_memory = []
                for word in word_dict:
                    if s.startswith(word):
                        current.append(word)
                        lefts = back_trace(s[len(word):], word_dict, current, result, memory)
                        current.pop()
                        current_memory.extend(
                            [word + (' ' if left else '') + left for left in lefts])
                memory[s] = current_memory
                return current_memory

        result = []
        back_trace(s, set(wordDict), [], result, {})
        return result
