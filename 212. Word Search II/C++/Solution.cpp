class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        class Utils {
        public:
            class TrieNode {
            public:
                vector<TrieNode *> next;
                string word;
                bool hasWord = false;

                TrieNode() {
                    next = vector<TrieNode *>(26);
                }
            };

            TrieNode *buildTrie(vector<string> &words) {
                TrieNode *root = new TrieNode();
                for (auto &word : words) {
                    TrieNode *node = root;
                    for (auto letter : word) {
                        int key = letter - 'a';
                        if (node->next[key] == nullptr) {
                            node->next[key] = new TrieNode();
                        }
                        node = node->next[key];
                    }
                    node->word = word;
                    node->hasWord = true;
                }
                return root;
            }

            void
            backTrace(vector<vector<char>> &board, int i, int j, int m, int n, TrieNode *node, vector<string> &result) {
                if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' ||
                    node->next[board[i][j] - 'a'] == nullptr) {
                    return;
                }
                char letter = board[i][j];
                node = node->next[letter - 'a'];
                if (node->hasWord) {
                    result.push_back(node->word);
                    node->hasWord = false;
                }
                board[i][j] = '#';
                backTrace(board, i - 1, j, m, n, node, result);
                backTrace(board, i + 1, j, m, n, node, result);
                backTrace(board, i, j - 1, m, n, node, result);
                backTrace(board, i, j + 1, m, n, node, result);
                board[i][j] = letter;
            }

            vector<string> go(vector<vector<char>> &board, vector<string> &words) {
                vector<string> result;
                TrieNode *root = buildTrie(words);
                int m = board.size();
                int n = board[0].size();
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        backTrace(board, i, j, m, n, root, result);
                    }
                }
                return result;
            }
        };
        Utils utils;
        return utils.go(board, words);
    }
};