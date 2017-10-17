class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        memory = {}
        for word in strs:
            sorted_word = ''.join(sorted(word))
            if sorted_word not in memory:
                memory[sorted_word] = []
            memory[sorted_word].append(word)
        return list(memory.values())
