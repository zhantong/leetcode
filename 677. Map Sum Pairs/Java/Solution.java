class MapSum {
    /**
     * Initialize your data structure here.
     */
    TrieNode root;
    Map<String, Integer> memory;

    public MapSum() {
        root = new TrieNode();
        memory = new HashMap<>();
    }

    public void insert(String key, int val) {
        if (memory.containsKey(key)) {
            val -= memory.get(key);
            memory.put(key, memory.get(key) + val);
        } else {
            memory.put(key, val);
        }
        TrieNode root = this.root;
        root.count += val;
        for (char letter : key.toCharArray()) {
            if (!root.children.containsKey(letter)) {
                root.children.put(letter, new TrieNode());
            }
            root = root.children.get(letter);
            root.count += val;
        }
    }

    public int sum(String prefix) {
        TrieNode root = this.root;
        for (char letter : prefix.toCharArray()) {
            if (!root.children.containsKey(letter)) {
                return 0;
            }
            root = root.children.get(letter);
        }
        return root.count;
    }

    class TrieNode {
        int count = 0;
        Map<Character, TrieNode> children = new HashMap<>();
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */