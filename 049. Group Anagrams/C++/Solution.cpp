class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> memory;
        for (const auto &word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            memory[sortedWord].push_back(word);
        }
        vector<vector<string>> result;
        for (const auto &item : memory) {
            result.push_back(item.second);
        }
        return result;
    }
};