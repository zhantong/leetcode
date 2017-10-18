class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freqDict;
        int maxFreq = -1;
        for (auto num : nums) {
            if (freqDict.find(num) == freqDict.end()) {
                freqDict[num] = 0;
            }
            freqDict[num]++;
            maxFreq = max(maxFreq, freqDict[num]);
        }
        vector<vector<int>> freqList(maxFreq + 1);
        for (auto item : freqDict) {
            freqList[item.second].push_back(item.first);
        }
        vector<int> result;
        for (int i = freqList.size() - 1; i > 0 && result.size() < k; i--) {
            if (!freqList[i].empty()) {
                result.insert(result.end(), freqList[i].begin(), freqList[i].end());
            }
        }
        return result;
    }
};