class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLength = ring.length();
        int keyLength = key.length();
        vector<vector<int>> dp(keyLength + 1, vector<int>(ringLength, 0));
        unordered_map<char, vector<int>> indexSame;
        for (auto item : key) {
            if (indexSame.find(item) == indexSame.end()) {
                for (int i = 0; i < ringLength; i++) {
                    if (item == ring[i]) {
                        indexSame[item].push_back(i);
                    }
                }
            }
        }
        for (int keyIndex = keyLength - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLength; ringIndex++) {
                dp[keyIndex][ringIndex] = INT_MAX;
                for (auto i : indexSame[key[keyIndex]]) {
                    int clockStep = abs(ringIndex - i);
                    int minStep = min(clockStep, ringLength - clockStep);
                    dp[keyIndex][ringIndex] = min(dp[keyIndex][ringIndex], minStep + dp[keyIndex + 1][i]);
                }
            }
        }
        return dp[0][0] + keyLength;
    }
};