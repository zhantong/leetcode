class MapSum {
    class TrieNode {
    public:
        int count = 0;
        unordered_map<char, TrieNode *> children;
    };

    TrieNode *root;
    unordered_map<string, int> memory;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        if (memory.count(key) != 0) {
            val -= memory[key];
            memory[key] += val;
        } else {
            memory[key] = val;
        }
        TrieNode *root = this->root;
        root->count += val;
        for (auto letter : key) {
            if (root->children.count(letter) == 0) {
                root->children[letter] = new TrieNode();
            }
            root = root->children[letter];
            root->count += val;
        }
    }

    int sum(string prefix) {
        TrieNode *root = this->root;
        for (auto letter : prefix) {
            if (root->children.count(letter) == 0) {
                return 0;
            }
            root = root->children[letter];
        }
        return root->count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */