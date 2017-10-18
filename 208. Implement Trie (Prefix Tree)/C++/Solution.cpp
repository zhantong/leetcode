class Trie {
public:
    class TrieNode {
    public:
        bool isWord = false;
        char val;
        vector<TrieNode *> children;

        TrieNode() {
            children = vector<TrieNode *>(26);
        }
    };

    /** Initialize your data structure here. */
    TrieNode *root = new TrieNode();

    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *current = root;
        for (auto letter : word) {
            if (current->children[letter - 'a'] == nullptr) {
                current->children[letter - 'a'] = new TrieNode();
                current->children[letter - 'a']->val = letter;
            }
            current = current->children[letter - 'a'];
        }
        current->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *current = root;
        for (auto letter : word) {
            if (current->children[letter - 'a'] == nullptr) {
                return false;
            }
            current = current->children[letter - 'a'];
        }
        return current->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for (auto letter : prefix) {
            if (current->children[letter - 'a'] == nullptr) {
                return false;
            }
            current = current->children[letter - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */