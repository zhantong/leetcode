class Solution {
public:
    int numTrees(int n) {
        vector<int> results(n + 1, 0);
        results[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                results[i] += results[j] * results[i - j - 1];
            }
        }
        return results[n];
    }
};