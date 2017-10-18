class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        class Utils {
        public:
            bool exist(vector<vector<char>> &board, string &word, int i, int j, int index) {
                if (index == word.length()) {
                    return true;
                }
                if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) {
                    return false;
                }
                char temp = board[i][j];
                board[i][j] = '0';
                if (exist(board, word, i + 1, j, index + 1)
                    || exist(board, word, i, j + 1, index + 1)
                    || exist(board, word, i - 1, j, index + 1)
                    || exist(board, word, i, j - 1, index + 1)) {
                    return true;
                }
                board[i][j] = temp;
                return false;
            }
        };
        Utils utils;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (utils.exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};