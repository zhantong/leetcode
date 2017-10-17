class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        class TrieNode {
            char val;
            TrieNode[] children;
            boolean isWord;

            public TrieNode(char val) {
                this.val = val;
                children = new TrieNode[26];
                isWord = false;
            }
        }
        class Utils {
            TrieNode buildTrie(List<String> words) {
                TrieNode root = new TrieNode(' ');
                for (String word : words) {
                    TrieNode current = root;
                    for (char letter : word.toCharArray()) {
                        int index = letter - 'a';
                        if (current.children[index] == null) {
                            current.children[index] = new TrieNode(letter);
                        }
                        current = current.children[index];
                    }
                    current.isWord = true;
                }
                return root;
            }

            String getRoot(String word, TrieNode trieRoot) {
                StringBuilder builder = new StringBuilder();
                for (char letter : word.toCharArray()) {
                    builder.append(letter);
                    int index = letter - 'a';
                    if (trieRoot.children[index] == null) {
                        return word;
                    }
                    if (trieRoot.children[index].isWord) {
                        return builder.toString();
                    }
                    trieRoot = trieRoot.children[index];
                }
                return word;
            }
        }
        Utils utils = new Utils();
        TrieNode trieRoot = utils.buildTrie(dict);
        StringBuilder builder = new StringBuilder();
        for (String word : sentence.split(" ")) {
            builder.append(utils.getRoot(word, trieRoot)).append(' ');
        }
        builder.deleteCharAt(builder.length() - 1);
        return builder.toString();
    }
}