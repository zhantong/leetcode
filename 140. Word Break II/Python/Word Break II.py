class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """

        def back_trace(s, word_dict, memory):
            if not s:
                return ['']
            if s in memory:
                return memory[s]
            current_memory = []
            for word in word_dict:
                if s.startswith(word):
                    lefts = back_trace(s[len(word):], word_dict, memory)
                    current_memory.extend([word + (' ' if left else '') + left for left in lefts])
            memory[s] = current_memory
            return current_memory

        return back_trace(s, wordDict, {})
