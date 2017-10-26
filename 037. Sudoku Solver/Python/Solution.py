class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def sudoku(board, pos):
            if pos == 81:
                return True
            i = pos // 9
            j = pos % 9
            if board[i][j] != '.':
                return sudoku(board, pos + 1)
            for letter in '123456789':
                if is_valid(board, i, j, letter):
                    board[i][j] = letter
                    if sudoku(board, pos + 1):
                        return True
            board[i][j] = '.'
            return False

        def is_valid(board, row, column, letter):
            for i in range(9):
                if board[i][column] == letter:
                    return False
            for j in range(9):
                if board[row][j] == letter:
                    return False
            for i in range(3 * (row // 3), 3 * (row // 3) + 3):
                for j in range(3 * (column // 3), 3 * (column // 3) + 3):
                    if board[i][j] == letter:
                        return False
            return True

        sudoku(board, 0)
