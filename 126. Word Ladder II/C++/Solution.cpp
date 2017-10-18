class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        class Utils {
        public:
            void backTrace(unordered_map<string, unordered_set<string>> &memory, vector<string> &current,
                           vector<vector<string>> &result, string word) {
                if (memory.find(word) == memory.end()) {
                    vector<string> temp(current);
                    reverse(temp.rbegin(), temp.rend());
                    result.push_back(temp);
                } else {
                    for (auto &item : memory[word]) {
                        current.push_back(item);
                        backTrace(memory, current, result, item);
                        current.pop_back();
                    }
                }
            }
        };
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(beginWord) != wordSet.end()) {
            wordSet.erase(beginWord);
        }
        if (wordSet.find(endWord) == wordSet.end()) {
            return vector<vector<string>>();
        }
        bool flag = false;
        unordered_map<string, unordered_set<string>> memory;
        while (!que.empty()) {
            int size = que.size();
            unordered_set<string> thisLevel;
            for (int i = 0; i < size; i++) {
                string current = que.front();
                que.pop();
                for (int j = 0; j < current.length(); j++) {
                    string temp = current;
                    for (char letter = 'a'; letter <= 'z'; letter++) {
                        temp[j] = letter;
                        if (temp == endWord || wordSet.find(temp) != wordSet.end()) {
                            memory[temp].insert(current);
                        }
                        if (temp == endWord) {
                            flag = true;
                        } else if (wordSet.find(temp) != wordSet.end()) {
                            thisLevel.insert(temp);
                        }
                    }
                }
            }
            for (auto &item : thisLevel) {
                wordSet.erase(item);
                que.push(item);
            }
            if (flag) {
                break;
            }
        }
        if (memory.empty()) {
            return vector<vector<string>>();
        }
        Utils utils;
        vector<vector<string>> result;
        vector<string> current;
        current.push_back(endWord);
        utils.backTrace(memory, current, result, endWord);
        return result;
    }
};