class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        istringstream isstream(str);
        string item;
        while (isstream >> item) {
            words.push_back(item);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        unordered_map<char, string> mapChar2String;
        unordered_map<string, char> mapString2Char;
        for (int i = 0; i < pattern.size(); i++) {
            char letter = pattern[i];
            string word = words[i];
            if (mapChar2String.find(letter) != mapChar2String.end()) {
                if (mapChar2String[letter] != word) {
                    return false;
                }
            } else {
                if (mapString2Char.find(word) != mapString2Char.end()) {
                    return false;
                }
                mapChar2String[letter] = word;
                mapString2Char[word] = letter;
            }
        }
        return true;
    }
};