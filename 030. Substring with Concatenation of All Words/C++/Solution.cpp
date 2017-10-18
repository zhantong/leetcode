class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        unordered_map<string, int> counts;
        int wordsLength = words.size();
        int wordLength = words[0].length();
        for (auto &word : words) {
            if (counts.find(word) == counts.end()) {
                counts[word] = 0;
            }
            counts[word]++;
        }
        for (int i = 0; i <= (int)s.length() - wordsLength * wordLength; i++) {
            unordered_map<string, int> currentCounts;
            int j = 0;
            while (j < wordsLength) {
                int index = i + j * wordLength;
                string current = s.substr(index, wordLength);
                if (counts.find(current) != counts.end()) {
                    if (currentCounts.find(current) == currentCounts.end()) {
                        currentCounts[current] = 0;
                    }
                    currentCounts[current]++;
                    if (currentCounts[current] > counts[current]) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == wordsLength) {
                result.push_back(i);
            }
        }
        return result;
    }
};