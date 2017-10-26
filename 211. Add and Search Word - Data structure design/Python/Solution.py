class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.val = None


class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        node = self.root
        for letter in word:
            if not node.children[ord(letter) - ord('a')]:
                node.children[ord(letter) - ord('a')] = TrieNode()
            node = node.children[ord(letter) - ord('a')]
        node.val = word

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """

        def search(word, index, node):
            if index == len(word):
                return node.val is not None
            if word[index] == '.':
                for child in node.children:
                    if child:
                        if (search(word, index + 1, child)):
                            return True
            else:
                child = node.children[ord(word[index]) - ord('a')]
                return child is not None and search(word, index + 1, child)
            return False

        return search(word, 0, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
