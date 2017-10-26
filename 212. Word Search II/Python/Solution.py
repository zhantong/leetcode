class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        class TrieNode:
            def __init__(self):
                self.next = [None] * 26
                self.word = None

        def build_trie(words):
            root = TrieNode()
            for word in words:
                node = root
                for letter in word:
                    key = ord(letter) - ord('a')
                    if not node.next[key]:
                        node.next[key] = TrieNode()
                    node = node.next[key]
                node.word = word
            return root

        def back_trace(board, i, j, m, n, node, result):
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] == '#' or not node.next[ord(board[i][j]) - ord('a')]:
                return
            letter = board[i][j]
            node = node.next[ord(letter) - ord('a')]
            if node.word:
                result.append(node.word)
                node.word = None
            board[i][j] = '#'
            back_trace(board, i - 1, j, m, n, node, result)
            back_trace(board, i + 1, j, m, n, node, result)
            back_trace(board, i, j - 1, m, n, node, result)
            back_trace(board, i, j + 1, m, n, node, result)
            board[i][j] = letter

        result = []
        root = build_trie(words)
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                back_trace(board, i, j, m, n, root, result)
        return result
