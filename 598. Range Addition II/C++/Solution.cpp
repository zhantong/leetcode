class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        int resultM = m;
        int resultN = n;
        for (const vector<int> &op : ops) {
            resultM = min(resultM, op[0]);
            resultN = min(resultN, op[1]);
        }
        return resultM * resultN;
    }
};