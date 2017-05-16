class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        i = click[0]
        j = click[1]
        if board[i][j] == 'M':
            board[i][j] = 'X'
        else:
            count = 0
            m = len(board)
            n = len(board[0])
            for a in range(-1, 2):
                for b in range(-1, 2):
                    p = i + a
                    q = j + b
                    if p >= 0 and q >= 0 and p < m and q < n and board[p][q] == 'M':
                        count += 1
            if count:
                board[i][j] = str(count)
            else:
                board[i][j] = 'B'
                for a in range(-1, 2):
                    for b in range(-1, 2):
                        p = i + a
                        q = j + b
                        if p >= 0 and q >= 0 and p < m and q < n and board[p][q] == 'E':
                            self.updateBoard(board, [p, q])
        return board
