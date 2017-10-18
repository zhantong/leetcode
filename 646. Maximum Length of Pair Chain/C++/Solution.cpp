class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        int result = 1;
        int current = pairs[0][1];
        for (auto &pair : pairs) {
            if (pair[0] > current) {
                current = pair[1];
                result++;
            }
        }
        return result;
    }
};