public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        class Utils {
            class TrieNode {
                TrieNode[] next = new TrieNode[26];
                String word = null;
            }

            TrieNode buildTrie(String[] words) {
                TrieNode root = new TrieNode();
                for (String word : words) {
                    TrieNode node = root;
                    for (char letter : word.toCharArray()) {
                        int key = letter - 'a';
                        if (node.next[key] == null) {
                            node.next[key] = new TrieNode();
                        }
                        node = node.next[key];
                    }
                    node.word = word;
                }
                return root;
            }

            void backTrace(char[][] board, int i, int j, int m, int n, TrieNode node, List<String> result) {
                if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' || node.next[board[i][j] - 'a'] == null) {
                    return;
                }
                char letter = board[i][j];
                node = node.next[letter - 'a'];
                if (node.word != null) {
                    result.add(node.word);
                    node.word = null;
                }
                board[i][j] = '#';
                backTrace(board, i - 1, j, m, n, node, result);
                backTrace(board, i + 1, j, m, n, node, result);
                backTrace(board, i, j - 1, m, n, node, result);
                backTrace(board, i, j + 1, m, n, node, result);
                board[i][j] = letter;
            }

            List<String> go(char[][] board, String[] words) {
                List<String> result = new ArrayList<>();
                TrieNode root = buildTrie(words);
                int m = board.length;
                int n = board[0].length;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        backTrace(board, i, j, m, n, root, result);
                    }
                }
                return result;
            }
        }
        Utils utils = new Utils();
        return utils.go(board, words);
    }
}