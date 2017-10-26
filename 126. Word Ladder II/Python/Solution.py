class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        def back_trace(memory, current, result, word):
            if word not in memory:
                result.append(current[::-1])
            else:
                for item in memory[word]:
                    current.append(item)
                    back_trace(memory, current, result, item)
                    current.pop()

        queue = collections.deque()
        queue.append(beginWord)
        word_set = set(wordList)
        if beginWord in word_set:
            word_set.remove(beginWord)
        if endWord not in word_set:
            return []
        flag = False
        memory = {}
        while queue:
            size = len(queue)
            this_level = set()
            for i in range(size):
                current = queue.popleft()
                for j in range(len(current)):
                    for letter in 'abcdefghijklmnopqrstuvwxyz':
                        temp = current[:j] + letter + current[j + 1:]
                        if temp == endWord:
                            if temp not in memory:
                                memory[temp] = set()
                            memory[temp].add(current)
                            flag = True
                        elif temp in word_set:
                            if temp not in memory:
                                memory[temp] = set()
                            memory[temp].add(current)
                            this_level.add(temp)
            for item in this_level:
                word_set.remove(item)
                queue.append(item)
            if flag:
                break
        result = []
        if not memory:
            return []
        back_trace(memory, [endWord], result, endWord)
        return result
