class MagicDictionary:
    class TrieNode:
        def __init__(self):
            self.is_word = False
            self.children = [None] * 26

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = self.TrieNode()

    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        for word in dict:
            current = self.root
            for letter in word:
                index = ord(letter) - ord('a')
                if current.children[index] is None:
                    current.children[index] = self.TrieNode()
                current = current.children[index]
            current.is_word = True

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """

        def dfs(word, root, index, is_changed):
            if index == len(word):
                return root.is_word and is_changed
            if is_changed:
                i = ord(word[index]) - ord('a')
                return (not root.children[i] is None) and dfs(word, root.children[i], index + 1, is_changed)
            for i in range(26):
                if root.children[i]:
                    if dfs(word, root.children[i], index + 1, False if ord(word[index]) - ord('a') == i else True):
                        return True
            return False

        return dfs(word, self.root, 0, False)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
