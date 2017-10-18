class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> results;
        int countChar = 0;
        vector<string> row;
        for (auto &word : words) {
            if (word.length() + countChar + row.size() > maxWidth) {
                if (row.size() == 1) {
                    string space(maxWidth - row[0].length(), ' ');
                    results.push_back(row[0] + space);
                } else {
                    int countSpace = (maxWidth - countChar) / (row.size() - 1);
                    int countExtra = (maxWidth - countChar) % (row.size() - 1);
                    string result = "";
                    string space(countSpace, ' ');
                    for (int i = 0; i < row.size() - 1; i++) {
                        result += row[i];
                        if (i < countExtra) {
                            result += " ";
                        }
                        result += space;
                    }
                    result += row.back();
                    results.push_back(result);
                }
                countChar = 0;
                row.clear();
            }
            countChar += word.length();
            row.push_back(word);
        }
        string result;
        for (auto &item : row) {
            result += item;
            result += " ";
        }
        result.erase(result.end() - 1);
        string space(maxWidth - result.length(), ' ');
        result += space;
        results.push_back(result);
        return results;
    }
};