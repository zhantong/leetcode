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
        Utils utils;

        map<char, int> pattern;
        pattern.insert({'q', 1});
        pattern.insert({'w', 1});
        pattern.insert({'e', 1});
        pattern.insert({'r', 1});
        pattern.insert({'t', 1});
        pattern.insert({'y', 1});
        pattern.insert({'u', 1});
        pattern.insert({'i', 1});
        pattern.insert({'o', 1});
        pattern.insert({'p', 1});
        pattern.insert({'a', 2});
        pattern.insert({'s', 2});
        pattern.insert({'d', 2});
        pattern.insert({'f', 2});
        pattern.insert({'g', 2});
        pattern.insert({'h', 2});
        pattern.insert({'j', 2});
        pattern.insert({'k', 2});
        pattern.insert({'l', 2});
        pattern.insert({'z', 3});
        pattern.insert({'x', 3});
        pattern.insert({'c', 3});
        pattern.insert({'v', 3});
        pattern.insert({'b', 3});
        pattern.insert({'n', 3});
        pattern.insert({'m', 3});
        vector <string> result;
        for (string word:words) {
            int category = pattern[utils.easytolower(word[0])];
            bool isSameCategory = true;
            for (char letter:word) {
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