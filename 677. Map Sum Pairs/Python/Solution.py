class MapSum:
    class TrieNode:
        def __init__(self):
            self.count = 0
            self.children = {}

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = self.TrieNode()
        self.memory = {}

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        if key in self.memory:
            val -= self.memory[key]
            self.memory[key] += val
        else:
            self.memory[key] = val

        root = self.root
        root.count += val
        for letter in key:
            if letter not in root.children:
                root.children[letter] = self.TrieNode()
            root = root.children[letter]
            root.count += val

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        root = self.root
        for letter in prefix:
            if letter not in root.children:
                return 0
            root = root.children[letter]
        return root.count


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
