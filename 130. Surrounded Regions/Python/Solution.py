class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def dfs(board, i, j):
            if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
                return
            board[i][j] = '1'
            if i > 1 and board[i - 1][j] == 'O':
                dfs(board, i - 1, j)
            if i < len(board) - 1 and board[i + 1][j] == 'O':
                dfs(board, i + 1, j)
            if j > 1 and board[i][j - 1] == 'O':
                dfs(board, i, j - 1)
            if j < len(board[0]) - 1 and board[i][j + 1] == 'O':
                dfs(board, i, j + 1)
        if not board:
            return
        m = len(board)
        n = len(board[0])
        for i in range(m):
            if board[i][0] == 'O':
                dfs(board, i, 0)
            if board[i][n - 1] == 'O':
                dfs(board, i, n - 1)
        for j in range(n):
            if board[0][j] == 'O':
                dfs(board, 0, j)
            if board[m - 1][j] == 'O':
                dfs(board, m - 1, j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '1':
                    board[i][j] = 'O'
