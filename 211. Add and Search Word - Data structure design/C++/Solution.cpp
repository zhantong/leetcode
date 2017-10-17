class WordDictionary {
public:
    class TrieNode {
    public:
        TrieNode *children[26];
        string val = "";
    };

    TrieNode *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for (auto &letter : word) {
            if (node->children[letter - 'a'] == nullptr) {
                node->children[letter - 'a'] = new TrieNode();
            }
            node = node->children[letter - 'a'];
        }
        node->val = word;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        class Utils {
        public:
            bool search(string word, int index, TrieNode *node) {
                if (index == word.length()) {
                    return !node->val.empty();
                }
                if (word[index] == '.') {
                    for (TrieNode *child : node->children) {
                        if (child != nullptr) {
                            if (search(word, index + 1, child)) {
                                return true;
                            }
                        }
                    }
                } else {
                    TrieNode *child = node->children[word[index] - 'a'];
                    return child != nullptr && search(word, index + 1, child);
                }
                return false;
            }
        };
        Utils utils;
        return utils.search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */