class Solution {
public:
    vector <string> findWords(vector <string> &words) {
        class Utils {
        public:
            char easytolower(char in) {
                if (in <= 'Z' && in >= 'A')
                    return in - ('Z' - 'z');
                return in;
            }
        };
        unordered_map<char, int> pattern;
        for (auto letter : "qwertyuiop") {
            pattern[letter] = 1;
        }
        for (auto letter : "asdfghjkl") {
            pattern[letter] = 2;
        }
        for (auto letter : "zxcvbnm") {
            pattern[letter] = 3;
        }
        Utils utils;
        vector <string> result;
        for (auto &word : words) {
            int category = pattern[utils.easytolower(word[0])];
            bool isSameCategory = true;
            for (auto letter : word) {
                if (pattern[utils.easytolower(letter)] != category) {
                    isSameCategory = false;
                    break;
                }
            }
            if (isSameCategory) {
                result.push_back(word);
            }
        }
        return result;
    }
};