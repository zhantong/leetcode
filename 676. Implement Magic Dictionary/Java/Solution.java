class MagicDictionary {
    TrieNode root;

    /**
     * Initialize your data structure here.
     */
    public MagicDictionary() {
        root = new TrieNode();
    }

    /**
     * Build a dictionary through a list of words
     */
    public void buildDict(String[] dict) {
        for (String word : dict) {
            TrieNode current = root;
            for (char letter : word.toCharArray()) {
                int index = letter - 'a';
                if (current.children[index] == null) {
                    current.children[index] = new TrieNode();
                }
                current = current.children[index];
            }
            current.isWord = true;
        }
    }

    boolean dfs(String word, TrieNode root, int index, boolean isChanged) {
        if (index == word.length()) {
            return root.isWord && isChanged;
        }
        if (isChanged) {
            int i = word.charAt(index) - 'a';
            return root.children[i] != null && dfs(word, root.children[i], index + 1, isChanged);
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != null) {
                if (dfs(word, root.children[i], index + 1, word.charAt(index) - 'a' != i)) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Returns if there is any word in the trie that equals to the given word after modifying exactly one character
     */
    public boolean search(String word) {
        return dfs(word, root, 0, false);
    }

    class TrieNode {
        boolean isWord = false;
        TrieNode[] children = new TrieNode[26];
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */