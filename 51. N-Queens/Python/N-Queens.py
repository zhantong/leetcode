class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        def back_trace(board, row_index, result):
            if row_index == len(board):
                result.append(convert(board))
                return
            for j in range(len(board[row_index])):
                if is_valid(board, row_index, j):
                    board[row_index][j] = 'Q'
                    back_trace(board, row_index + 1, result)
                    board[row_index][j] = '.'

        def convert(board):
            return [''.join(row) for row in board]

        def is_valid(board, i, j):
            for x in range(i):
                for y in range(len(board[i])):
                    if board[x][y] == 'Q' and (y == j or i - x == j - y or i - x == y - j):
                        return False
            return True

        board = [['.'] * n for i in range(n)]
        result = []
        back_trace(board, 0, result)
        return result
