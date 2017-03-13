class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                count = 0
                for a in range(i - 1, i + 2):
                    for b in range(j - 1, j + 2):
                        if a >= 0 and b >= 0 and a < m and b < n and board[a][b] & 1:
                            count += 1
                count -= board[i][j] & 1
                if (board[i][j] & 1 and (count == 2 or count == 3)) or (not board[i][j] & 1 and count == 3):
                    board[i][j] |= 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
