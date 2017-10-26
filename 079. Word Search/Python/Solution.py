class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def exist(board, word, i, j, index):
            if index == len(word):
                return True
            if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or board[i][j] != word[index]:
                return False
            temp = board[i][j]
            board[i][j] = '0'
            if exist(board, word, i + 1, j, index + 1) \
                    or exist(board, word, i, j + 1, index + 1) \
                    or exist(board, word, i - 1, j, index + 1) \
                    or exist(board, word, i, j - 1, index + 1):
                return True
            board[i][j] = temp
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if exist(board, word, i, j, 0):
                    return True
        return False
