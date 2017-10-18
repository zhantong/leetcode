class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqDict;
        int maxFreq = -1;
        for (auto letter : s) {
            if (freqDict.find(letter) == freqDict.end()) {
                freqDict[letter] = 0;
            }
            freqDict[letter]++;
            maxFreq = max(maxFreq, freqDict[letter]);
        }
        vector<vector<char>> freqList(maxFreq + 1);
        for (auto item : freqDict) {
            freqList[item.second].push_back(item.first);
        }
        string result;
        for (int i = freqList.size() - 1; i > 0; i--) {
            if (!freqList[i].empty()) {
                for (char letter : freqList[i]) {
                    for (int j = 0; j < i; j++) {
                        result.push_back(letter);
                    }
                }
            }
        }
        return result;
    }
};