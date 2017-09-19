class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """

        class TrieNode:
            def __init__(self, val):
                self.val = val
                self.children = [None] * 26
                self.is_word = False

        def build_trie(words):
            root = TrieNode(' ')
            for word in words:
                current = root
                for letter in word:
                    index = ord(letter) - ord('a')
                    if not current.children[index]:
                        current.children[index] = TrieNode(letter)
                    current = current.children[index]
                current.is_word = True
            return root

        def get_root(word, trie_root):
            current = ''
            for letter in word:
                current += letter
                index = ord(letter) - ord('a')
                if not trie_root.children[index]:
                    return word
                if trie_root.children[index].is_word:
                    return current
                trie_root = trie_root.children[index]
            return word

        trie_root = build_trie(dict)
        result = ''
        for word in sentence.split():
            result += get_root(word, trie_root) + ' '
        return result[:-1]
