public class WordDictionary {
    TrieNode root;

    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String val = "";
    }

    /**
     * Initialize your data structure here.
     */
    public WordDictionary() {
        root = new TrieNode();
    }

    /**
     * Adds a word into the data structure.
     */
    public void addWord(String word) {
        TrieNode node = root;
        for (char letter : word.toCharArray()) {
            if (node.children[letter - 'a'] == null) {
                node.children[letter - 'a'] = new TrieNode();
            }
            node = node.children[letter - 'a'];
        }
        node.val = word;
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
     */
    public boolean search(String word) {
        class Utils {
            boolean search(String word, int index, TrieNode node) {
                if (index == word.length()) {
                    return !node.val.isEmpty();
                }
                if (word.charAt(index) == '.') {
                    for (TrieNode child : node.children) {
                        if (child != null) {
                            if (search(word, index + 1, child)) {
                                return true;
                            }
                        }
                    }
                } else {
                    TrieNode child = node.children[word.charAt(index) - 'a'];
                    return child != null && search(word, index + 1, child);
                }
                return false;
            }
        }
        Utils utils = new Utils();
        return utils.search(word, 0, root);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */