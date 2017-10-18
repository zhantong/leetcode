class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        class Utils {
        public:
            vector<string>
            backTrace(string s, vector<string> &wordDict, unordered_map<string, vector<string>> &memory) {
                if (s.empty()) {
                    vector<string> result;
                    result.push_back("");
                    return result;
                }
                if (memory.find(s) != memory.end()) {
                    return memory[s];
                }
                vector<string> currentMemory;
                for (auto &word : wordDict) {
                    if (s.find(word) == 0) {
                        vector<string> lefts = backTrace(s.substr(word.length()), wordDict, memory);
                        for (auto &left : lefts) {
                            currentMemory.push_back(word + (left.empty() ? "" : " ") + left);
                        }
                    }
                }
                memory[s] = currentMemory;
                return currentMemory;
            }
        };
        Utils utils;
        unordered_map<string, vector<string>> temp;
        return utils.backTrace(s, wordDict, temp);
    }
};