class Solution {
public:
    string replaceWords(vector<string> &dict, string sentence) {
        class Utils {
        public:
            class TrieNode {
            public:
                char val;
                TrieNode *children[26] = {};
                bool isWord = false;

                TrieNode(char val) {
                    this->val = val;
                }
            };

            TrieNode *trieRoot;

            TrieNode *buildTrie(vector<string> &words) {
                TrieNode *root = new TrieNode(' ');
                for (auto &word : words) {
                    TrieNode *current = root;
                    for (auto letter : word) {
                        int index = letter - 'a';
                        if (current->children[index] == nullptr) {
                            current->children[index] = new TrieNode(letter);
                        } else if (current->children[index]->isWord) {
                            current = current->children[index];
                            break;
                        }
                        current = current->children[index];
                    }
                    current->isWord = true;
                    if (root->children['h' - 'a'] != nullptr && root->children['h' - 'a']->isWord) {
                        cout << word << endl;
                    }
                }
                trieRoot = root;
                return root;
            }

            string getRoot(string word) {
                string builder = "";
                TrieNode *root = trieRoot;
                for (auto letter : word) {
                    builder += letter;
                    int index = letter - 'a';
                    if (root->children[index] == nullptr) {
                        if (word == "h") {
                            printf("out");
                        }
                        return word;
                    }
                    if (root->children[index]->isWord) {
                        if (builder == "h") {
                            printf("builder");
                        }
                        return builder;
                    }
                    root = root->children[index];
                }
                return word;
            }
        };
        Utils utils;
        utils.buildTrie(dict);
        string builder;
        stringstream ss(sentence);
        string word;
        while (getline(ss, word, ' ')) {
            if (word == "h") {
                printf("out");
            }
            builder += utils.getRoot(word);
            builder += ' ';
        }
        builder.pop_back();
        return builder;
    }
};