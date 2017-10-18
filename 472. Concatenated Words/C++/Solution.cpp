class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> result;
        unordered_set<string> wordsSet;
        sort(words.begin(), words.end(), [](const string & a, const string & b) {
            return a.length() < b.length();
        });

        for (auto &word : words) {
            if (!wordsSet.empty()) {
                int length = word.length();
                vector<bool> dp(length + 1, false);
                dp[0] = true;
                for (int i = 0; i <= length; i++) {
                    for (int j = 0; j < i; j++) {
                        if (!dp[j]) {
                            continue;
                        }
                        if (wordsSet.find(word.substr(j, i - j)) != wordsSet.end()) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
                if (dp[length]) {
                    result.push_back(word);
                }
            }
            wordsSet.insert(word);
        }
        return result;
    }
};