class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for row in board:
            counts = [None] * 9
            for item in row:
                if item != '.':
                    if counts[ord(item) - ord('1')] == 1:
                        return False
                    counts[ord(item) - ord('1')] = 1
        for j in range(9):
            counts = [None] * 9
            for i in range(9):
                item = board[i][j]
                if item != '.':
                    if counts[ord(item) - ord('1')] == 1:
                        return False
                    counts[ord(item) - ord('1')] = 1
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                counts = [None] * 9
                for a in range(i, i + 3):
                    for b in range(j, j + 3):
                        item = board[a][b]
                        if item != '.':
                            if counts[ord(item) - ord('1')] == 1:
                                return False
                            counts[ord(item) - ord('1')] = 1
        return True
