class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> sumABDict;
        for (auto &a : A) {
            for (auto &b : B) {
                int sumAB = a + b;
                if (sumABDict.find(sumAB) == sumABDict.end()) {
                    sumABDict[sumAB] = 0;
                }
                sumABDict[sumAB]++;
            }
        }
        int result = 0;
        for (int c : C) {
            for (int d : D) {
                int sumCD = -c - d;
                if (sumABDict.find(sumCD) != sumABDict.end()) {
                    result += sumABDict[sumCD];
                }
            }
        }
        return result;
    }
};