class MagicDictionary {
    class TrieNode {
    public:
        bool isWord = false;
        TrieNode *children[26];
    };

    TrieNode *root;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &word : dict) {
            TrieNode *current = root;
            for (auto letter : word) {
                int index = letter - 'a';
                if (current->children[index] == nullptr) {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->isWord = true;
        }
    }

    bool dfs(string &word, TrieNode *root, int index, bool isChanged) {
        if (index == word.size()) {
            return root->isWord && isChanged;
        }
        if (isChanged) {
            int i = word[index] - 'a';
            return root->children[i] != nullptr && dfs(word, root->children[i], index + 1, isChanged);
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                if (dfs(word, root->children[i], index + 1, word[index] - 'a' != i)) {
                    return true;
                }
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(word, root, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */