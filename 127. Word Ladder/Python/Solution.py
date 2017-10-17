class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        queue = collections.deque()
        queue.append(beginWord)
        count = 0
        word_set = set(wordList)
        while queue:
            size = len(queue)
            for i in range(size):
                current = queue.popleft()
                if current == endWord:
                    return count + 1
                for j in range(len(current)):
                    for letter in 'abcdefghijklmnopqrstuvwxyz':
                        temp = current[:j] + letter + current[j + 1:]
                        if temp in word_set:
                            queue.append(temp)
                            word_set.remove(temp)
            count += 1
        return 0
