class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> result;
        result.push_back("");
        vector<string> pattern{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (const auto &digit : digits) {
            vector<string> tempResult;
            for (const auto &item : result) {
                for (const auto &letter : pattern[digit - '0']) {
                    tempResult.push_back(item + letter);
                }
            }
            result = tempResult;
        }
        return result;
    }
};