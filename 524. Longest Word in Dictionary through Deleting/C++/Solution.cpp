class Solution {
public:
    string findLongestWord(string s, vector<string> &d) {
        sort(d.begin(), d.end(), [](const string & a, const string & b) {
            if (a.length() == b.length()) {
                return a < b;
            } else {
                return a.length() > b.length();
            }
        });
        for (auto &word : d) {
            int i = 0;
            for (auto letter : s) {
                if (letter == word[i]) {
                    i++;
                }
                if (i == word.length()) {
                    break;
                }
            }
            if (i == word.length()) {
                return word;
            }
        }
        return "";
    }
};