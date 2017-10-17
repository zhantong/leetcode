public class Trie {

    TrieNode root = new TrieNode();

    class TrieNode {
        boolean isWord = false;
        char val;
        TrieNode[] children = new TrieNode[26];
    }

    /**
     * Initialize your data structure here.
     */
    public Trie() {

    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        TrieNode current = root;
        for (char letter : word.toCharArray()) {
            if (current.children[letter - 'a'] == null) {
                current.children[letter - 'a'] = new TrieNode();
                current.children[letter - 'a'].val = letter;
            }
            current = current.children[letter - 'a'];
        }
        current.isWord = true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        TrieNode current = root;
        for (char letter : word.toCharArray()) {
            if (current.children[letter - 'a'] == null) {
                return false;
            }
            current = current.children[letter - 'a'];
        }
        return current.isWord;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (char letter : prefix.toCharArray()) {
            if (current.children[letter - 'a'] == null) {
                return false;
            }
            current = current.children[letter - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */