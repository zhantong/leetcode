class TrieNode:
    def __init__(self):
        self.is_word = False
        self.val = None
        self.children = [None] * 26


class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        current = self.root
        for letter in word:
            if not current.children[ord(letter) - ord('a')]:
                current.children[ord(letter) - ord('a')] = TrieNode()
                current.children[ord(letter) - ord('a')].val = letter
            current = current.children[ord(letter) - ord('a')]
        current.is_word = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        current = self.root
        for letter in word:
            if not current.children[ord(letter) - ord('a')]:
                return False
            current = current.children[ord(letter) - ord('a')]
        return current.is_word

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        current = self.root
        for letter in prefix:
            if not current.children[ord(letter) - ord('a')]:
                return False
            current = current.children[ord(letter) - ord('a')]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
